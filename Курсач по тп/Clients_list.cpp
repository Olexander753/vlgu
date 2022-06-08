#include "Clients_list.h"
#include <iostream>

int c = 0;

System::Void Курсачпотп::Clients_list::button_load_Click(System::Object^ sender, System::EventArgs^ e)
{
    while (c != 0)
    {
        dataGridView1->Rows->RemoveAt(c - 1);
        c = c - 1;
    }

    Connection connect;
    connect.ConnectToBD();
    connect.conn->Open();

    String^ cmdText = "select Client.Full_name, Client.DLN, Client.Phone_number, Users.Login_, Users.Password_ from Client inner join Users on Client.DLN = Users.FK_DLN";
    SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);
     
    SqlDataReader^ dbreader = cmd->ExecuteReader();

    if (dbreader->HasRows == false)
        MessageBox::Show("Ошибка считывания данных", "Ошибка!");
    else
    {
        while (dbreader->Read())
        {
            dataGridView1->Rows->Add(dbreader["Full_name"], dbreader["DLN"], dbreader["Phone_number"], dbreader["Login_"], dbreader["Password_"]);
            c++;
        }
    }

    dbreader->Close();
    connect.conn->Close();
    return System::Void();
}

System::Void Курсачпотп::Clients_list::button_Add_Click(System::Object^ sender, System::EventArgs^ e)
{
    Add_client_Form^ Add_client_form = gcnew Add_client_Form;
    Add_client_form->Show();
    return System::Void();
}

System::Void Курсачпотп::Clients_list::button_Update_Click(System::Object^ sender, System::EventArgs^ e)
{
    setlocale(LC_ALL, "RUS");
    try
    {
        if (dataGridView1->SelectedRows->Count != 1)
        {
            MessageBox::Show("Выберите одну строку для изменения", "Внимание!");
            return;
        }
        int index = dataGridView1->SelectedRows[0]->Index;

        if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[4]->Value == nullptr)
        {
            MessageBox::Show("Введены не все данные!", "Внимание!");
            return;
        }

        Client^ client = gcnew Client;

        client->Full_Name = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
        client->DLN = Convert::ToDouble(dataGridView1->Rows[index]->Cells[1]->Value->ToString());
        client->P_Number = Convert::ToDouble(dataGridView1->Rows[index]->Cells[2]->Value->ToString());
        client->Login = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
        client->Password = dataGridView1->Rows[index]->Cells[4]->Value->ToString();

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText_rollback;
        String^ cmdText_commit;

        String^ cmdText = "begin tran UPDATE Client Set Full_name = '" + client->Full_Name + "', Phone_number = " + client->P_Number + " WHERE DLN = " + client->DLN + ";";
        cmdText += "UPDATE Users Set Login_ = '" + client->Login + "', Password_ = '" + client->Password + "' where FK_DLN = " + client->DLN;
        cmdText_rollback = cmdText + "rollback";
        SqlCommand^ cmd = gcnew SqlCommand(cmdText_rollback, connect.conn);

        if (cmd->ExecuteNonQuery() != 2)
        {
            MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
        }
        else
        {
            cmdText_commit = cmdText + "commit";
            SqlCommand^ cmd1 = gcnew SqlCommand(cmdText_commit, connect.conn);
            if (cmd1->ExecuteNonQuery() == 2)
                MessageBox::Show("Данные добалены!", "Готово!");
        }

        connect.conn->Close();
        return System::Void();
    }
    catch (SqlException^ ex)
    {
        String^ Error = ex->Errors->ToString();
        MessageBox::Show("Проверьте правильность введённыйх данных!", "Ошибка!");
        return System::Void();
    }
}

System::Void Курсачпотп::Clients_list::button_Delete_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        if (dataGridView1->SelectedRows->Count != 1)
        {
            MessageBox::Show("Выберите одну строку для изменения", "Внимание!");
            return;
        }

        int index;
        if (c == 1)
            index = 0;
        else
            index = dataGridView1->SelectedRows[0]->Index;

        Client^ client = gcnew Client;
        client->DLN = Convert::ToDouble(dataGridView1->Rows[index]->Cells[1]->Value->ToString());

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText = "DELETE FROM Client WHERE DLN = " + client->DLN;
        SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

        if (cmd->ExecuteNonQuery() < 1)
            MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
        else
        {
            MessageBox::Show("Данные изменены!", "Готово!");
            dataGridView1->Rows->RemoveAt(index);
            c--;
        }

        connect.conn->Close();
        return System::Void();
    }
    catch (SqlException^ ex)
    {
        String^ Error = ex->Errors->ToString();
        MessageBox::Show("Проверьте правильность введённыйх данных!\n" +ex, "Ошибка!");
        return System::Void();
    }
}

System::Void Курсачпотп::Clients_list::button_Back_Click(System::Object^ sender, System::EventArgs^ e)
{
    c = 0;
    Owner->Show();
    this->Hide();
    return System::Void();
}

System::Void Курсачпотп::Clients_list::button_Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}
