#include "Add_client_Form.h"
#include <iostream>


System::Void ����������::Add_client_Form::button_Enter_Click(System::Object^ sender, System::EventArgs^ e)
{
    setlocale(LC_ALL, "RUS");
    try 
    {
        if (textBox_Full_name->Text == nullptr ||
            textBox_DLN->Text == nullptr ||
            textBox_Phone_number->Text == nullptr ||
            textBox_Login == nullptr ||
            textBox_Password == nullptr)
        {
            MessageBox::Show("������� �� ��� ������!", "��������!");
            return;
        }

        Client^ client = gcnew Client;

        client->Full_Name = textBox_Full_name->Text;
        client->DLN = Convert::ToDouble(textBox_DLN->Text);
        client->P_Number = Convert::ToDouble(textBox_Phone_number->Text);
        client->Login = textBox_Login->Text;
        client->Password = textBox_Password->Text;

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText_rollback;
        String^ cmdText_commit;

        String^ cmdText = "begin tran insert into Client values ('" + client->Full_Name + "', " + client->DLN + ", " + client->P_Number + ");";
        cmdText += " insert into Users(Login_, Password_, Role_, FK_DLN) values('" + client->Login + "', '" + client->Password + "', '������', " + client->DLN + ");";
        cmdText_rollback = cmdText + " rollback";
        SqlCommand^ cmd = gcnew SqlCommand(cmdText_rollback, connect.conn);

        if (cmd->ExecuteNonQuery() != 2)
        {
            MessageBox::Show("������ ���������� �������!", "������!");
        }
        else
        {
            cmdText_commit = cmdText + " commit";
            SqlCommand^ cmd1 = gcnew SqlCommand(cmdText_commit, connect.conn);
            if (cmd1->ExecuteNonQuery() == 2)
                MessageBox::Show("������ ��������!", "������!");
        }

        connect.conn->Close();
        this->Hide();

        return System::Void();
    }

    catch (SqlException^ ex)
    {
        String^ Error = ex->Errors->ToString();
        MessageBox::Show("��������� ������������ ��������� ������!", "������!");
        return System::Void();
    }
}

System::Void ����������::Add_client_Form::button_Back_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    return System::Void();
}

System::Void ����������::Add_client_Form::button_Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}
