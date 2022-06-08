#include "Staff_list.h"
#include <iostream>

int a = 0;
int b = 0;

System::Void Курсачпотп::Staff_list::button_load_Click(System::Object^ sender, System::EventArgs^ e)
{
    while (a != 0)
    {
        dataGridView1->Rows->RemoveAt(a - 1);
        a = a - 1;
    }

    Connection connect;
    connect.ConnectToBD();
    connect.conn->Open();

    String^ cmdText = "select Co_worker.PN, Manager.Full_name, Manager.Passport_data, Manager.Phone_number, Users.Login_, Users.Password_ from Manager inner join Co_worker on Manager.Passport_data = Co_worker.FK_Manager_Passport_data inner join Users on Co_worker.PN = Users.FK_PN";
    SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

    SqlDataReader^ dbreader = cmd->ExecuteReader();

    if (dbreader->HasRows == false)
        MessageBox::Show("Ошибка считывания данных", "Ошибка!");
    else
    {
        while (dbreader->Read())
        {
            dataGridView1->Rows->Add(dbreader["PN"], dbreader["Full_name"], dbreader["Passport_data"], dbreader["Phone_number"], dbreader["Login_"], dbreader["Password_"]);
            a++;
        }
    }

    dbreader->Close();
    connect.conn->Close();
    return System::Void();
}

System::Void Курсачпотп::Staff_list::button_Add_Click(System::Object^ sender, System::EventArgs^ e)
{
    Add_manager_Form^ Add_manager_form = gcnew Add_manager_Form();
    Add_manager_form->Show();
    return System::Void();
}

System::Void Курсачпотп::Staff_list::button_Edit_Click(System::Object^ sender, System::EventArgs^ e)
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
            dataGridView1->Rows[index]->Cells[4]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[5]->Value == nullptr)
        {
            MessageBox::Show("Введены не все данные!", "Внимание!");
            return;
        }
        Manager^ manager = gcnew Manager();
        manager->PN = Convert::ToInt32(dataGridView1->Rows[index]->Cells[0]->Value->ToString());
        manager->Full_name = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
        manager->P_data = Convert::ToDouble(dataGridView1->Rows[index]->Cells[2]->Value->ToString());
        manager->P_number = Convert::ToDouble(dataGridView1->Rows[index]->Cells[3]->Value->ToString());
        manager->Login = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
        manager->Password = dataGridView1->Rows[index]->Cells[5]->Value->ToString();

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText_rollback;
        String^ cmdText_commit;

        String^ cmdText = "begin tran UPDATE Manager Set Full_name = '" + manager->Full_name + "', Phone_number = " + manager->P_number + " WHERE Passport_data = " + manager->P_data + ";";
        cmdText += "UPDATE Users Set Login_ = '" + manager->Login + "', Password_ = '" + manager->Password + "' where FK_PN = " + manager->PN;
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

System::Void Курсачпотп::Staff_list::button_Delete_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        if (dataGridView1->SelectedRows->Count != 1)
        {
            MessageBox::Show("Выберите одну строку для изменения", "Внимание!");
            return;
        }

        int index;
        if (a == 1)
            index = 0;
        else
            index = dataGridView1->SelectedRows[0]->Index;

        Manager^ manager = gcnew Manager;
        manager->P_data = Convert::ToDouble(dataGridView1->Rows[index]->Cells[2]->Value->ToString());

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText = "DELETE FROM Manager WHERE Passport_data = " + manager->P_data;
        SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

        if (cmd->ExecuteNonQuery() < 1)
            MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
        else
        {
            MessageBox::Show("Данные изменены!", "Готово!");
            dataGridView1->Rows->RemoveAt(index);
            a--;
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

System::Void Курсачпотп::Staff_list::button_load__Click(System::Object^ sender, System::EventArgs^ e)
{
    while (b != 0)
    {
        dataGridView2->Rows->RemoveAt(b - 1);
        b = b - 1;
    }

    Connection connect;
    connect.ConnectToBD();
    connect.conn->Open();

    String^ cmdText = "select Co_worker.PN, Mechanic.Full_name, Mechanic.Passport_data, Mechanic.Phone_number, Mechanic.Qualification, Users.Login_, Users.Password_ from Mechanic inner join Co_worker on Mechanic.Passport_data = Co_worker.FK_Mechanic_Passport_data inner join Users on Co_worker.PN = Users.FK_PN";
    SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

    SqlDataReader^ dbreader = cmd->ExecuteReader();

    if (dbreader->HasRows == false)
        MessageBox::Show("Ошибка считывания данных", "Ошибка!");
    else
    {
        while (dbreader->Read())
        {
            dataGridView2->Rows->Add(dbreader["PN"], dbreader["Full_name"], dbreader["Passport_data"], dbreader["Phone_number"], dbreader["Qualification"], dbreader["Login_"], dbreader["Password_"]);
            b++;
        }
    }

    dbreader->Close();
    connect.conn->Close();
    return System::Void();
}

System::Void Курсачпотп::Staff_list::button_Add__Click(System::Object^ sender, System::EventArgs^ e)
{
    Add_mechanic_Form^ Add_mechanic_form = gcnew Add_mechanic_Form();
    Add_mechanic_form->Show();
    return System::Void();
}

System::Void Курсачпотп::Staff_list::button_Edit__Click(System::Object^ sender, System::EventArgs^ e)
{
    setlocale(LC_ALL, "RUS");
    try
    {
        if (dataGridView2->SelectedRows->Count != 1)
        {
            MessageBox::Show("Выберите одну строку для изменения", "Внимание!");
            return;
        }
        int index = dataGridView2->SelectedRows[0]->Index;

        if (dataGridView2->Rows[index]->Cells[0]->Value == nullptr ||
            dataGridView2->Rows[index]->Cells[1]->Value == nullptr ||
            dataGridView2->Rows[index]->Cells[2]->Value == nullptr ||
            dataGridView2->Rows[index]->Cells[3]->Value == nullptr ||
            dataGridView2->Rows[index]->Cells[4]->Value == nullptr ||
            dataGridView2->Rows[index]->Cells[5]->Value == nullptr ||
            dataGridView2->Rows[index]->Cells[6]->Value == nullptr)
        {
            MessageBox::Show("Введены не все данные!", "Внимание!");
            return;
        }

        Mechanic^ mechanic = gcnew Mechanic();
        mechanic->PN = Convert::ToInt32(dataGridView2->Rows[index]->Cells[0]->Value->ToString());
        mechanic->Full_name = dataGridView2->Rows[index]->Cells[1]->Value->ToString();
        mechanic->P_data = Convert::ToDouble(dataGridView2->Rows[index]->Cells[2]->Value->ToString());
        mechanic->P_number = Convert::ToDouble(dataGridView2->Rows[index]->Cells[3]->Value->ToString());
        mechanic->Qualification = dataGridView2->Rows[index]->Cells[4]->Value->ToString();
        mechanic->Login = dataGridView2->Rows[index]->Cells[5]->Value->ToString();
        mechanic->Password = dataGridView2->Rows[index]->Cells[6]->Value->ToString();

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText_rollback;
        String^ cmdText_commit;

        String^ cmdText = "begin tran UPDATE Mechanic Set Full_name = '" + mechanic->Full_name + "', Phone_number = " + mechanic->P_number + " , Qualification = '" + mechanic->Qualification + "' WHERE Passport_data = " + mechanic->P_data + ";";
        cmdText += "UPDATE Users Set Login_ = '" + mechanic->Login + "', Password_ = '" + mechanic->Password + "' where FK_PN = " + mechanic->PN + "; ";
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

System::Void Курсачпотп::Staff_list::button_delete__Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        if (dataGridView2->SelectedRows->Count != 1)
        {
            MessageBox::Show("Выберите одну строку для изменения", "Внимание!");
            return;
        }
        int index;
        if (b == 1)
            index = 0;
        else
            index = dataGridView2->SelectedRows[0]->Index;

        Mechanic^ mechanic = gcnew Mechanic();
        mechanic->P_data = Convert::ToDouble(dataGridView2->Rows[index]->Cells[2]->Value->ToString());

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText = "DELETE FROM Mechanic WHERE Passport_data = " + mechanic->P_data;
        SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

        if (cmd->ExecuteNonQuery() < 1)
            MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
        else
        {
            MessageBox::Show("Данные изменены!", "Готово!");
            dataGridView2->Rows->RemoveAt(index);
            b--;
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

System::Void Курсачпотп::Staff_list::button_Back_Click(System::Object^ sender, System::EventArgs^ e)
{
    a = 0;
    b = 0;
    Owner->Show();
    this->Hide();
    return System::Void();
}

System::Void Курсачпотп::Staff_list::button_Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}
