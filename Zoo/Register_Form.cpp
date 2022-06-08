#include "Register_Form.h"

System::Void Zoo::Register_Form::Register_Form_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    this->Hide();
    return System::Void();
}

System::Void Zoo::Register_Form::button_register_Click(System::Object^ sender, System::EventArgs^ e)
{
    setlocale(LC_ALL, "RUS");
    try
    {
        if (textBox_full_name->Text == nullptr ||
            textBox_phone_number->Text == nullptr ||
            textBox_password->Text == nullptr)
        {
            MessageBox::Show("Введены не все данные!", "Внимание!");
            return;
        }

        Visitor^ visitor = gcnew Visitor;
        User^ user = gcnew User;

        visitor->Full_name = textBox_full_name->Text;
        visitor->Phone_number = Convert::ToDouble(textBox_phone_number->Text);
        user->Login = textBox_phone_number->Text;
        user->Password = textBox_password->Text;
        user->Role = "Посетитель";

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText_rollback;
        String^ cmdText_commit;
        String^ cmdText;

        cmdText = "begin tran ";
        cmdText += "insert into Visitor values('"+visitor->Full_name+"', "+visitor->Phone_number+");";
        cmdText += "insert into User_(Login_, Password_, Role_, FK_Phone_number) values('" + user->Login + "', '" + user->Password + "', '" + user->Role + "', " + visitor->Phone_number + ");";
        cmdText_rollback = cmdText + " rollback";

        SqlCommand^ cmd = gcnew SqlCommand(cmdText_rollback, connect.conn);

        if (cmd->ExecuteNonQuery() != 2)
        {
            MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
        }
        else if (cmd->ExecuteNonQuery() == 2)
        {
            cmdText_commit = cmdText + " commit";
            SqlCommand^ cmd1 = gcnew SqlCommand(cmdText_commit, connect.conn);
            if (cmd1->ExecuteNonQuery() == 2)
                MessageBox::Show("Данные добалены!", "Готово!");
        }
        connect.conn->Close();
        this->Hide();
        return System::Void();
    }
    catch (SqlException^ ex)
    {
        String^ Error = ex->Errors->ToString();
        MessageBox::Show("Проверьте правильность введённыйх данных!\n " + ex + "", "Ошибка!");
        return System::Void();
    }
}
