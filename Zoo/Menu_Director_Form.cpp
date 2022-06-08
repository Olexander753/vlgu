#include "Menu_Director_Form.h"

System::Void Zoo::Menu_Director_Form::обновитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    int size_Zoo = 0;
    size_Zoo = dataGridView_Zoo->RowCount - 1;
    while (size_Zoo != 0)
    {
        dataGridView_Zoo->Rows->RemoveAt(size_Zoo - 1);
        size_Zoo = size_Zoo - 1;
    }
    try
    {
        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText = "select * from Zoo";
        SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

        SqlDataReader^ dbreader = cmd->ExecuteReader();

        if (dbreader->HasRows == false)
            MessageBox::Show("Ошибка считывания данных", "Ошибка!");
        else
        {
            while (dbreader->Read())
            {
                dataGridView_Zoo->Rows->Add(dbreader["ID"], dbreader["Title"], dbreader["Square_"], dbreader["Address_"], dbreader["Job_status"]);
                size_Zoo++;
            }
        }

        dbreader->Close();
        connect.conn->Close();

        return System::Void();
    }
    catch (SqlException^ ex)
    {
        String^ Error = ex->Errors->ToString();
        MessageBox::Show("Проверьте правильность введённыйх данных!\n" + ex + "", "Ошибка!");
        return System::Void();
    }
}

System::Void Zoo::Menu_Director_Form::button_Enter_Click(System::Object^ sender, System::EventArgs^ e)
{
    int size_food = 0;
    int size_employee = 0;
    Menu_Zoo_Form^ Menu_Zoo_form = gcnew Menu_Zoo_Form;

    if (dataGridView_Zoo->SelectedRows->Count != 1)
    {
        MessageBox::Show("Выберите одну строку для изменения", "Внимание!");
        return;
    }
    int index = dataGridView_Zoo->SelectedRows[0]->Index;

    Zoopark^ zoo = gcnew Zoopark;

    zoo->ID = Convert::ToInt32(dataGridView_Zoo->Rows[index]->Cells[0]->Value->ToString());

    Connection connect;
    connect.ConnectToBD();
    connect.conn->Open();

    String^ cmdText_Employee = "select Service_number, Full_name, Passport_data, Login_, Password_  from Employee inner join User_ on User_.FK_Service_number_Employee = Employee.Service_number WHERE FK_ID_Zoo = " + zoo->ID;
    SqlCommand^ cmd = gcnew SqlCommand(cmdText_Employee, connect.conn);

    SqlDataReader^ dbreader = cmd->ExecuteReader();

    if (dbreader->HasRows == false)
        MessageBox::Show("В данном зоопарке нет сотудников", "Ошибка!");
    else
    {
        while (dbreader->Read())
        {
            Menu_Zoo_form->dataGridView_Employee->Rows->Add(dbreader["Service_number"], dbreader["Full_name"], dbreader["Passport_data"], dbreader["Login_"], dbreader["Password_"]);
            size_employee++;
        }
    }

    dbreader->Close();

    String^ cmdText_Food = "select Food.ID, Food.Title, Food.Qty from Food inner join Animal on Animal.ID = Food.FK_ID_Animal where Animal.FK_ID_Zoo = " + zoo->ID;
    SqlCommand^ cmd1 = gcnew SqlCommand(cmdText_Food, connect.conn);

    SqlDataReader^ dbreader2 = cmd1->ExecuteReader();

    if (dbreader2->HasRows == false)
        MessageBox::Show("В данном зоопарке нет корма", "Ошибка!");
    else
    {
        while (dbreader2->Read())
        {
            Menu_Zoo_form->dataGridView_Food->Rows->Add(dbreader2["ID"], dbreader2["Title"], dbreader2["Qty"]);
            size_employee++;
        }
    }

    dbreader2->Close();
    connect.conn->Close();

    Menu_Zoo_form->label_Zoo_ID->Text = Convert::ToString(zoo->ID);
    Menu_Zoo_form->Show();
    Menu_Zoo_form->Owner = this;
    this->Hide();

    return System::Void();
}

System::Void Zoo::Menu_Director_Form::button_Open_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        if (dataGridView_Zoo->SelectedRows->Count != 1)
        {
            MessageBox::Show("Выберите одну строку для изменения", "Внимание!");
            return;
        }
        int index = dataGridView_Zoo->SelectedRows[0]->Index;

        Zoopark^ zoo = gcnew Zoopark();

        zoo->ID = Convert::ToInt32(dataGridView_Zoo->Rows[index]->Cells[0]->Value->ToString());

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText_rollback;
        String^ cmdText_commit;

        String^ cmdText = "begin tran UPDATE Zoo Set Job_status = 'Открыт' WHERE ID = " + zoo->ID;
        cmdText_rollback = cmdText + "rollback";
        SqlCommand^ cmd = gcnew SqlCommand(cmdText_rollback, connect.conn);

        if (cmd->ExecuteNonQuery() != 1)
        {
            MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
        }
        else if (cmd->ExecuteNonQuery() == 1)
        {
            cmdText_commit = cmdText + "commit";
            SqlCommand^ cmd1 = gcnew SqlCommand(cmdText_commit, connect.conn);
            if (cmd1->ExecuteNonQuery() == 1)
            {
                MessageBox::Show("Данные добалены!", "Готово!");
                dataGridView_Zoo->Rows[index]->Cells[4]->Value = "Открыт";
            }

        }

        connect.conn->Close();

        return System::Void();
    }
    catch (SqlException^ ex)
    {
        String^ Error = ex->Errors->ToString();
        MessageBox::Show("Проверьте правильность введённыйх данных!\n" + ex + "", "Ошибка!");
        return System::Void();
    }
}

System::Void Zoo::Menu_Director_Form::button_Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        if (dataGridView_Zoo->SelectedRows->Count != 1)
        {
            MessageBox::Show("Выберите одну строку для изменения", "Внимание!");
            return;
        }
        int index = dataGridView_Zoo->SelectedRows[0]->Index;

        Zoopark^ zoo = gcnew Zoopark();

        zoo->ID = Convert::ToInt32(dataGridView_Zoo->Rows[index]->Cells[0]->Value->ToString());

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText_rollback;
        String^ cmdText_commit;

        String^ cmdText = "begin tran UPDATE Zoo Set Job_status = 'Закрыт' WHERE ID = " + zoo->ID;
        cmdText_rollback = cmdText + "rollback";
        SqlCommand^ cmd = gcnew SqlCommand(cmdText_rollback, connect.conn);

        if (cmd->ExecuteNonQuery() != 1)
        {
            MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
        }
        else if (cmd->ExecuteNonQuery() == 1)
        {
            cmdText_commit = cmdText + "commit";
            SqlCommand^ cmd1 = gcnew SqlCommand(cmdText_commit, connect.conn);
            if (cmd1->ExecuteNonQuery() == 1)
            {
                MessageBox::Show("Данные добалены!", "Готово!");
                dataGridView_Zoo->Rows[index]->Cells[4]->Value = "Закрыт";
            }
                
        }

        connect.conn->Close();

        return System::Void();
    }
    catch (SqlException^ ex)
    {
        String^ Error = ex->Errors->ToString();
        MessageBox::Show("Проверьте правильность введённыйх данных!\n"+ex+"", "Ошибка!");
        return System::Void();
    }
}

System::Void Zoo::Menu_Director_Form::Menu_Director_Form_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    Application::Exit();
    return System::Void();
}
