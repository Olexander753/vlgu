#include "Add_manager_Form.h"
#include <iostream>

System::Void Курсачпотп::Add_manager_Form::button_back_Click(System::Object^ sender, System::EventArgs^ e)
{
    Owner->Show();
    this->Hide();
    return System::Void();
}

System::Void Курсачпотп::Add_manager_Form::button_exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

System::Void Курсачпотп::Add_manager_Form::button_add_Click(System::Object^ sender, System::EventArgs^ e)
{
    setlocale(LC_ALL, "RUS");
    try
    {
        if (textBox_Full_name->Text == nullptr ||
            textBox_Login->Text == nullptr ||
            textBox_Number->Text == nullptr ||
            textBox_Passport_data == nullptr ||
            textBox_Password->Text == nullptr)
        {
            MessageBox::Show("Введены не все данные!", "Внимание!");
            return;
        }

        Manager^ manager = gcnew Manager();
        manager->Full_name = textBox_Full_name->Text;
        manager->P_data = Convert::ToDouble(textBox_Passport_data->Text);
        manager->P_number = Convert::ToDouble(textBox_Number->Text);
        manager->Login = textBox_Login->Text;
        manager->Password = textBox_Password->Text;
        String^ Post = "Менеджер";

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText_rollback;
        String^ cmdText_commit;

        String^ cmdText = "begin tran insert into Manager values ('" + manager->Full_name + "', " + manager->P_data + ", '" + manager->P_number + "');";
        cmdText += "insert into Co_worker(Post, FK_Manager_Passport_data) values('" + Post + "', " + manager->P_data + ");";
        cmdText += "declare @a int = (select PN from Co_worker where Co_worker.FK_Manager_Passport_data = " + manager->P_data + ");";
        cmdText += "insert into Users(Login_, Password_, Role_, FK_PN) values('" + manager->Login + "', '" + manager->Password + "', '" + Post + "', @a);";
        cmdText_rollback = cmdText + "rollback";
        SqlCommand^ cmd = gcnew SqlCommand(cmdText_rollback, connect.conn);

        if (cmd->ExecuteNonQuery() != 3)
        {
            MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
        }
        else
        {
            cmdText_commit = cmdText + "commit";
            SqlCommand^ cmd1 = gcnew SqlCommand(cmdText_commit, connect.conn);
            if (cmd1->ExecuteNonQuery() == 3)
                MessageBox::Show("Данные добалены!", "Готово!");
        }

        connect.conn->Close();
        this->Hide();

        return System::Void();
    }
    catch (SqlException^ ex)
    {
        String^ Error = ex->Errors->ToString();
        MessageBox::Show("Проверьте правильность введённыйх данных!", "Ошибка!");
        return System::Void();
    }
}
