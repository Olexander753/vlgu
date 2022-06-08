#include "Detals_list.h"
#include "Detal.h"
#include <iostream>

int k = 0;

System::Void Курсачпотп::Detals_list::button_load_Click(System::Object^ sender, System::EventArgs^ e)
{
    while (k != 0)
    {
        dataGridView1->Rows->RemoveAt(k - 1);
        k = k - 1;
    }

    Connection connect;
    connect.ConnectToBD();
    connect.conn->Open();

    String^ cmdText = "select * from Detail";
    SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

    SqlDataReader^ dbreader = cmd->ExecuteReader();
    
    if (dbreader->HasRows == false)
        MessageBox::Show("Ошибка считывания данных", "Ошибка!");
    else
    {
        while (dbreader->Read())
        {
            dataGridView1->Rows->Add(dbreader["ID"], dbreader["Title"], dbreader["Price"], dbreader["Quantity"]);
            k++;
        }
    }

    dbreader->Close();
    connect.conn->Close();
    return System::Void();
}

System::Void Курсачпотп::Detals_list::button_Add_Click(System::Object^ sender, System::EventArgs^ e)
{
    Add_detals_Form^ Add_detal_form = gcnew Add_detals_Form;
    Add_detal_form->Show();
    return System::Void();
}

System::Void Курсачпотп::Detals_list::button_Edit_Click(System::Object^ sender, System::EventArgs^ e)
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
            dataGridView1->Rows[index]->Cells[3]->Value == nullptr)
        {
            MessageBox::Show("Введены не все данные!", "Внимание!");
            return;
        }

        Detal^ detal = gcnew Detal();
        detal->Vender_code = Convert::ToInt32(dataGridView1->Rows[index]->Cells[0]->Value->ToString());
        detal->Name = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
        detal->Price = Convert::ToDouble(dataGridView1->Rows[index]->Cells[2]->Value->ToString());
        detal->Quantity = Convert::ToInt32(dataGridView1->Rows[index]->Cells[3]->Value->ToString());

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

        String^ cmdText = "begin tran UPDATE Detail Set Title = '" + detal->Name + "', Price = " + s2 + ", Quantity = " + detal->Quantity + " WHERE ID = " + detal->Vender_code;
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
        return System::Void();
    }
    catch (SqlException^ ex)
    {
        String^ Error = ex->Errors->ToString();
        MessageBox::Show("Проверьте правильность введённыйх данных!", "Ошибка!");
        return System::Void();
    }
}

System::Void Курсачпотп::Detals_list::button_Delete_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        if (dataGridView1->SelectedRows->Count != 1)
        {
            MessageBox::Show("Выберите одну строку для изменения", "Внимание!");
            return;
        }

        int index = dataGridView1->SelectedRows[0]->Index;

        String^ Vendor_code = dataGridView1->Rows[index]->Cells[0]->Value->ToString();

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText = "DELETE FROM Detail WHERE ID = '" + Vendor_code + "'";
        SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

        if (cmd->ExecuteNonQuery() != 1)
            MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
        else
        {
            MessageBox::Show("Данные изменены!", "Готово!");
            dataGridView1->Rows->RemoveAt(index);
            k--;
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

System::Void Курсачпотп::Detals_list::button_Back_Click(System::Object^ sender, System::EventArgs^ e)
{
    k = 0;
    Owner->Show();
    this->Hide();
    return System::Void();
}

System::Void Курсачпотп::Detals_list::button_Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}