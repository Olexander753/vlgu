#include "Menu_Zoo_Form.h"
#include "Animal.h"

System::Void Zoo::Menu_Zoo_Form::обновитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    int size_employee = 0;
    size_employee = dataGridView_Employee->RowCount - 1;
    while (size_employee != 0)
    {
        dataGridView_Employee->Rows->RemoveAt(size_employee - 1);
        size_employee = size_employee - 1;
    }

    int size_food = 0;
    size_food = dataGridView_Food->RowCount - 1;
    while (size_food != 0)
    {
        dataGridView_Food->Rows->RemoveAt(size_food - 1);
        size_food = size_food - 1;
    }

    Zoopark^ zoo = gcnew Zoopark;

    zoo->ID = Convert::ToInt32(label_Zoo_ID->Text);

    Connection connect;
    connect.ConnectToBD();
    connect.conn->Open();

    String^ cmdText_Employee = "select Service_number, Full_name, Passport_data, Login_, Password_  from Employee inner join User_ on User_.FK_Service_number_Employee = Employee.Service_number WHERE FK_ID_Zoo = " + zoo->ID;
    SqlCommand^ cmd = gcnew SqlCommand(cmdText_Employee, connect.conn);

    SqlDataReader^ dbreader = cmd->ExecuteReader();

    if (dbreader->HasRows == false)
        MessageBox::Show("Ошибка считывания данных о сотрудниках!", "Ошибка!");
    else
    {
        while (dbreader->Read())
        {
            dataGridView_Employee->Rows->Add(dbreader["Service_number"], dbreader["Full_name"], dbreader["Passport_data"], dbreader["Login_"], dbreader["Password_"]);
            size_employee++;
        }
    }

    dbreader->Close();

    String^ cmdText_Food = "select Food.ID, Food.Title, Food.Qty from Food inner join Animal on Animal.ID = Food.FK_ID_Animal where Animal.FK_ID_Zoo = " + zoo->ID;
    SqlCommand^ cmd1 = gcnew SqlCommand(cmdText_Food, connect.conn);

    SqlDataReader^ dbreader2 = cmd1->ExecuteReader();

    if (dbreader2->HasRows == false)
        MessageBox::Show("Ошибка считывания данных о корме!", "Ошибка!");
    else
    {
        while (dbreader2->Read())
        {
            dataGridView_Food->Rows->Add(dbreader2["ID"], dbreader2["Title"], dbreader2["Qty"]);
            size_employee++;
        }
    }

    return System::Void();
}

System::Void Zoo::Menu_Zoo_Form::button_Add_Employee_Click(System::Object^ sender, System::EventArgs^ e)
{
    Add_Employee_Form^ Add_Employee_form = gcnew Add_Employee_Form;

    Add_Employee_form->label5->Text = label_Zoo_ID->Text;

    Add_Employee_form->Show();
    return System::Void();
}

System::Void Zoo::Menu_Zoo_Form::button_Update_Click(System::Object^ sender, System::EventArgs^ e)
{
    Update_Employee_Form^ Update_Employee_form = gcnew Update_Employee_Form;

    if (dataGridView_Employee->SelectedRows->Count != 1)
    {
        MessageBox::Show("Выберите одну строку для изменения", "Внимание!");
        return;
    }
    int index = dataGridView_Employee->SelectedRows[0]->Index;

    Update_Employee_form->textBox_Full_name->Text = Convert::ToString(dataGridView_Employee->Rows[index]->Cells[1]->Value->ToString());
    Update_Employee_form->textBox_Passport_data->Text = Convert::ToString(dataGridView_Employee->Rows[index]->Cells[2]->Value->ToString());
    Update_Employee_form->textBox_Login->Text = Convert::ToString(dataGridView_Employee->Rows[index]->Cells[3]->Value->ToString());
    Update_Employee_form->textBox_Password->Text = Convert::ToString(dataGridView_Employee->Rows[index]->Cells[4]->Value->ToString());
    Update_Employee_form->label6->Text = dataGridView_Employee->Rows[index]->Cells[0]->Value->ToString();
    Update_Employee_form->label7->Text = label_Zoo_ID->Text;

    Update_Employee_form->Show();

    return System::Void();
}

System::Void Zoo::Menu_Zoo_Form::button_Delete_Employee_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        if (dataGridView_Employee->SelectedRows->Count != 1)
        {
            MessageBox::Show("Выберите одну строку для изменения", "Внимание!");
            return;
        }

        int index = dataGridView_Employee->SelectedRows[0]->Index;

        Employee^ employee = gcnew Employee();
        employee->Service_number = Convert::ToInt32(dataGridView_Employee->Rows[index]->Cells[0]->Value->ToString());

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText = "DELETE FROM Employee WHERE Service_number = " + employee->Service_number;
        SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

        if (cmd->ExecuteNonQuery() < 1)
            MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
        else
        {
            MessageBox::Show("Данные изменены!", "Готово!");
            dataGridView_Employee->Rows->RemoveAt(index);
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

System::Void Zoo::Menu_Zoo_Form::button_Add_food_Click(System::Object^ sender, System::EventArgs^ e)
{
    Add_Food_Form^ Add_Food_form = gcnew Add_Food_Form;
    ListBox^ list = gcnew ListBox;

    Connection connect;
    connect.ConnectToBD();
    connect.conn->Open();

    String^ Zoo_ID = label_Zoo_ID->Text;

    String^ cmdText = "select ID, Name_ from Animal where FK_ID_Zoo =" + Zoo_ID;
    SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

    SqlDataReader^ dbreader = cmd->ExecuteReader();

    Animal^ animal = gcnew Animal;

    while (dbreader->Read())
    {
        animal->ID = Convert::ToInt32(dbreader["ID"]->ToString());
        animal->Name = (dbreader["Name_"]->ToString());
        list->Items->Add(String::Format("{0}-{1}", animal->ID, animal->Name));

    }

    Add_Food_form->comboBox_Animal->DataSource = list->Items;

    Add_Food_form->Show();
    return System::Void();
}

System::Void Zoo::Menu_Zoo_Form::button_write_off_Click(System::Object^ sender, System::EventArgs^ e)
{
     try
    {
        if (dataGridView_Food->SelectedRows->Count != 1)
        {
            MessageBox::Show("Выберите одну строку для изменения", "Внимание!");
            return;
        }

        int index = dataGridView_Food->SelectedRows[0]->Index;

        Food^ food = gcnew Food;
        food->ID = Convert::ToInt32(dataGridView_Food->Rows[index]->Cells[0]->Value->ToString());

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText = "DELETE FROM Food WHERE ID = " + food->ID;
        SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

        if (cmd->ExecuteNonQuery() < 1)
            MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
        else
        {
            MessageBox::Show("Данные изменены!", "Готово!");
            dataGridView_Food->Rows->RemoveAt(index);
        }

        connect.conn->Close();
        return System::Void();
    }
    catch (SqlException^ ex)
    {
        String^ Error = ex->Errors->ToString();
        MessageBox::Show("Проверьте правильность введённыйх данных!\n "+ex+"", "Ошибка!");
        return System::Void();
    }
}

System::Void Zoo::Menu_Zoo_Form::назадToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Owner->Show();
    this->Hide();
    return System::Void();
}

System::Void Zoo::Menu_Zoo_Form::Menu_Zoo_Form_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

System::Void Zoo::Menu_Zoo_Form::button_Edit_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        if (dataGridView_Food->SelectedRows->Count != 1)
        {
            MessageBox::Show("Выберите одну строку для изменения", "Внимание!");
            return;
        }
        int index = dataGridView_Food->SelectedRows[0]->Index;

        if (dataGridView_Food->Rows[index]->Cells[0]->Value == nullptr ||
            dataGridView_Food->Rows[index]->Cells[1]->Value == nullptr ||
            dataGridView_Food->Rows[index]->Cells[2]->Value == nullptr)
        {
            MessageBox::Show("Введены не все данные!", "Внимание!");
            return;
        }

        Food^ food = gcnew Food;
        food->ID = Convert::ToInt32(dataGridView_Food->Rows[index]->Cells[0]->Value->ToString());
        food->Qty = Convert::ToInt32(dataGridView_Food->Rows[index]->Cells[2]->Value->ToString());

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText_rollback;
        String^ cmdText_commit;

        String^ cmdText = "begin tran UPDATE Food Set Qty = '" + food->Qty + "' WHERE ID = " + food->ID;
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
        MessageBox::Show("Проверьте правильность введённыйх данных!\n " + ex + "", "Ошибка!");
        return System::Void();
    }
}
