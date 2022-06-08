#include "main_menu.h"

int t = 0;

System::Void Курсачпотп::main_menu::button_back_Click(System::Object^ sender, System::EventArgs^ e)
{
    t = 0;
    Owner->Show();
    this->Hide();
    return System::Void();
}

System::Void Курсачпотп::main_menu::button_exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

System::Void Курсачпотп::main_menu::main_menu_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

System::Void Курсачпотп::main_menu::button_load_Click(System::Object^ sender, System::EventArgs^ e)
{
    while (t != 0)
    {
        dataGridView1->Rows->RemoveAt(t - 1);
        t = t - 1;
    }

    Connection connect;
    connect.ConnectToBD();
    connect.conn->Open();

    String^ cmdText = "select Repair.ID, Client.Full_name as F1, Car.Number, Mechanic.Full_name as F2, Type_Repair.Title as T1, Detail.Title as T2, Repair.Quantity, Repair.Date_, Repair.Total_price, Repair.Status_  from Repair inner join Car on Repair.FK_Number = Car.Number inner join Client on Car.FK_DLN = Client.DLN inner join Mechanic on Repair.FK_Passport_data = Mechanic.Passport_data inner join Type_repair on Repair.FK_ID_repair = Type_repair.ID left join Detail on Repair.FK_ID_detail = Detail.ID";
    SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

    SqlDataReader^ dbreader = cmd->ExecuteReader();

    if (dbreader->HasRows == false)
        MessageBox::Show("Ошибка считывания данных", "Ошибка!");
    else
    {
        while (dbreader->Read())
        {
            dataGridView1->Rows->Add(dbreader["ID"], dbreader["F1"], dbreader["Number"], dbreader["F2"], dbreader["T1"]
                , dbreader["T2"], dbreader["Quantity"], dbreader["Date_"], dbreader["Total_price"], dbreader["Status_"]);
            t++;
        }
    }

    dbreader->Close();
    connect.conn->Close();
    return System::Void();
}

System::Void Курсачпотп::main_menu::button_create_Click(System::Object^ sender, System::EventArgs^ e)
{
    Add_request_Form^ Add_request_form = gcnew Add_request_Form;
    Repair repair;
    Mechanic mechanic;
    Detal detal;

    Add_request_form->comboBox_Repair->DataSource = repair.FillComndoBox_Repairs();
    Add_request_form->comboBox_Mechanics->DataSource = mechanic.FillComndoBox_Mechanics();
    Add_request_form->comboBox_Detal->DataSource = detal.FillComndoBox_Detals();
    Add_request_form->Show();
    return System::Void();
}

System::Void Курсачпотп::main_menu::button_edit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Update_request_Form^ Update_request_form = gcnew Update_request_Form;
    Repair repair1;
    Repair^ repair2;
    Mechanic mechanic1;
    Mechanic^ mechanic2;
    Detal detal1;
    Detal^ detal2;
    Request^ request = gcnew Request();
    int log_quantity;

    if (dataGridView1->SelectedRows->Count != 1)
    {
        MessageBox::Show("Выберите одну строку для изменения", "Внимание!");
        return;
    }
    int index = dataGridView1->SelectedRows[0]->Index;
    
    request->ID = Convert::ToInt32(dataGridView1->Rows[index]->Cells[0]->Value->ToString());
    request->Date = Convert::ToString(dataGridView1->Rows[index]->Cells[7]->Value->ToString());
    
    Connection connect;
    connect.ConnectToBD();
    connect.conn->Open();
    String^ cmdText = "select Repair.ID, Client.DLN, Car.Number, Car.Brand, Car.Model, Mechanic.Full_name , Repair.FK_ID_repair as ID1, Type_repair.Title as T1, Repair.FK_ID_detail as ID2, Detail.Title as T2, Repair.Quantity  from Repair inner join Car on Repair.FK_Number = Car.Number inner join Client on Car.FK_DLN = Client.DLN inner join Mechanic on Repair.FK_Passport_data = Mechanic.Passport_data inner join Type_repair on Repair.FK_ID_repair = Type_repair.ID left join Detail on Repair.FK_ID_detail = Detail.ID where Repair.ID =" + request->ID;
    SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

    SqlDataReader^ dbreader = cmd->ExecuteReader();

    if (dbreader->HasRows == false)
        MessageBox::Show("Ошибка считывания данных", "Ошибка!");
    else
    {
        while (dbreader->Read())
        {
            request->ID = Convert::ToInt32(dbreader["ID"]);
            request->DLN = Convert::ToDouble(dbreader["DLN"]);
            request->Number = Convert::ToString(dbreader["Number"]);
            request->Brand = Convert::ToString(dbreader["Brand"]);
            request->Model = Convert::ToString(dbreader["Model"]);
            mechanic2->Full_name = Convert::ToString(dbreader["Full_name"]);
            repair2->ID = Convert::ToInt32(dbreader["ID1"]);
            repair2->Name = Convert::ToString(dbreader["T1"]);
            if (dataGridView1->Rows[index]->Cells[5]->Value->ToString() != "")
            {
                detal2->Vender_code = Convert::ToInt32(dbreader["ID2"]);
                detal2->Name = Convert::ToString(dbreader["T2"]);
                request->Quantity = Convert::ToInt32(dbreader["Quantity"]);
                log_quantity = request->Quantity;;
            }
            
        }
            
    }

    dbreader->Close();
    connect.conn->Close();

    Update_request_form->comboBox_Repair->DataSource = repair1.FillComndoBox_Repairs_Update(repair2);
    Update_request_form->comboBox_Mechanics->DataSource = mechanic1.FillComndoBox_Mechanics_Update(mechanic2); 
    Update_request_form->textBox_DLN->Text = Convert::ToString(request->DLN);
    Update_request_form->textBox_Brand_of_car->Text = request->Brand;
    Update_request_form->textBox_Mode_of_car->Text = request->Model;
    Update_request_form->textBox_Number_of_car->Text = request->Number;
    if (dataGridView1->Rows[index]->Cells[5]->Value->ToString() != "")
    {
        Update_request_form->comboBox_Detal->DataSource = detal1.FillComndoBox_Detals_Update(detal2);
        Update_request_form->textBox_Quantity_detals->Text = Convert::ToString(request->Quantity);
        Update_request_form->label13->Text = Convert::ToString(log_quantity);
    }
    else
        Update_request_form->comboBox_Detal->DataSource = detal1.FillComndoBox_Detals();
    Update_request_form->label9->Text = Convert::ToString(request->ID);
    Update_request_form->label12->Text = Convert::ToString(request->Date);
    Update_request_form->Show();
    return System::Void();
}

System::Void Курсачпотп::main_menu::button_delete_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        if (dataGridView1->SelectedRows->Count != 1)
        {
            MessageBox::Show("Выберите одну строку для изменения", "Внимание!");
            return;
        }

        int index;
        if (t == 1)
            index = 0;
        else
            index = dataGridView1->SelectedRows[0]->Index;

        Request^ request = gcnew Request();
        request->ID = Convert::ToInt32(dataGridView1->Rows[index]->Cells[0]->Value->ToString());

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText = "DELETE FROM Repair WHERE ID = " + request->ID;
        SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

        if (cmd->ExecuteNonQuery() < 1)
            MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
        else
        {
            MessageBox::Show("Данные изменены!", "Готово!");
            dataGridView1->Rows->RemoveAt(index);
            t--;
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

System::Void Курсачпотп::main_menu::button_Client_list_Click(System::Object^ sender, System::EventArgs^ e)
{
    Clients_list^ Clients_list_Frorm = gcnew Clients_list;
    Clients_list_Frorm->Show();
    Clients_list_Frorm->Owner = this;
    this->Hide();
    return System::Void();
}