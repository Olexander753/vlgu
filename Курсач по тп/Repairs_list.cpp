#include "Repairs_list.h"
#include <iostream>

int r = 0;

System::Void Курсачпотп::Repairs_list::button_load_Click(System::Object^ sender, System::EventArgs^ e)
{
    while (r != 0)
    {
        dataGridView1->Rows->RemoveAt(r - 1);
        r = r - 1;
    }

    Connection connect;
    connect.ConnectToBD();
    connect.conn->Open();

    String^ cmdText = "select * from Type_repair";
    SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

    SqlDataReader^ dbreader = cmd->ExecuteReader();

    if (dbreader->HasRows == false)
        MessageBox::Show("Ошибка считывания данных", "Ошибка!");
    else
    {
        while (dbreader->Read())
        {
            dataGridView1->Rows->Add(dbreader["ID"], dbreader["Title"], dbreader["Price"]);
            r++;
        }
    }

    dbreader->Close();
    connect.conn->Close();
    return System::Void();
}

System::Void Курсачпотп::Repairs_list::button_Add_Click(System::Object^ sender, System::EventArgs^ e)
{
    Add_repair_Form^ Add_repair_form = gcnew  Add_repair_Form;
    Add_repair_form->Show();
    return System::Void();
}

System::Void Курсачпотп::Repairs_list::button_Edit_Click(System::Object^ sender, System::EventArgs^ e)
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
            dataGridView1->Rows[index]->Cells[2]->Value == nullptr)
        {
            MessageBox::Show("Введены не все данные!", "Внимание!");
            return;
        }

        Repair^ repair = gcnew Repair();
        repair->ID = Convert::ToInt32(dataGridView1->Rows[index]->Cells[0]->Value->ToString());
        repair->Name = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
        repair->Price = Convert::ToDouble(dataGridView1->Rows[index]->Cells[2]->Value->ToString());

        int i = 0;
        String^ s;
        String^ s2;
        double pr = repair->Price;

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

        String^ cmdText = "begin tran UPDATE Type_repair Set Title = '" + repair->Name + "', Price = " + s2 + " WHERE ID = " + repair->ID;
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

System::Void Курсачпотп::Repairs_list::button_Delete_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        if (dataGridView1->SelectedRows->Count != 1)
        {
            MessageBox::Show("Выберите одну строку для изменения", "Внимание!");
            return;
        }

        int index = dataGridView1->SelectedRows[0]->Index;

        String^ ID = dataGridView1->Rows[index]->Cells[0]->Value->ToString();

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText = "DELETE FROM Type_repair WHERE ID = '" + ID + "'";
        SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

        if (cmd->ExecuteNonQuery() < 1)
            MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
        else
        {
            MessageBox::Show("Данные изменены!", "Готово!");
            dataGridView1->Rows->RemoveAt(index);
            r--;
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

System::Void Курсачпотп::Repairs_list::button_Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

System::Void Курсачпотп::Repairs_list::button_Back_Click(System::Object^ sender, System::EventArgs^ e)
{
    r = 0;
    Owner->Show();
    this->Hide();
    return System::Void();
}
