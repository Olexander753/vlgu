#include "Add_detals_Form.h"
#include <iostream>

System::Void Курсачпотп::Add_detals_Form::button_Back_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    return System::Void();
}

System::Void Курсачпотп::Add_detals_Form::button_Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

System::Void Курсачпотп::Add_detals_Form::button_Add_Click(System::Object^ sender, System::EventArgs^ e)
{
    setlocale(LC_ALL, "RUS");
    try
    {
        if (textBox_Name->Text == nullptr ||
            textBox_Price->Text == nullptr ||
            textBox_Quantity->Text == nullptr)
        {
            MessageBox::Show("Введены не все данные!", "Внимание!");
            return;
        }

        Detal^ detal = gcnew Detal();
        detal->Name = textBox_Name->Text;
        detal->Price = Convert::ToDouble(textBox_Price->Text);
        detal->Quantity = Convert::ToInt32(textBox_Quantity->Text);

        int i = 0;
        String^ s;
        String^ s2;
        double pr = detal->Price;

        s = Convert::ToString(pr);
        for (int i = 0; i < s->Length; i++)
        {
            if (s[i] != ',')
                s2 += s[i];
            else
                s2 += ".";
        }

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText_rollback;
        String^ cmdText_commit;

        String^ cmdText = "begin tran insert into Detail(Title, Price, Quantity) values ('" + detal->Name + "', " + s2 + ", " + detal->Quantity + ")";
        cmdText_rollback = cmdText + "rollback";
        SqlCommand^ cmd = gcnew SqlCommand(cmdText_rollback, connect.conn);

        if (cmd->ExecuteNonQuery() != 1)
        {
            MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
        }
        else
        {
            cmdText_commit = cmdText + "commit";
            SqlCommand^ cmd1 = gcnew SqlCommand(cmdText_commit, connect.conn);
            if (cmd1->ExecuteNonQuery() == 1)
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
