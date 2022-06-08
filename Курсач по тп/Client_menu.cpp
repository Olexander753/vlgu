#include "Client_menu.h"

int z = 0;

System::Void Курсачпотп::Client_menu::button_load_Click(System::Object^ sender, System::EventArgs^ e)
{
    while (z != 0)
    {
        dataGridView1->Rows->RemoveAt(z - 1);
        z = z - 1;
    }

	Client^ client = gcnew Client;
	
	client->DLN = Convert::ToDouble(DLN_label->Text);

	Connection connect;
	connect.ConnectToBD();
	connect.conn->Open();

	String^ cmdText = "SELECT Car.Number, Car.Brand, Car.Model, Type_repair.Title, Repair.Total_price, Repair.Status_ FROM Repair inner join Car on Repair.FK_Number = Car.Number inner join Type_repair on Repair.FK_ID_repair = Type_repair.ID where FK_DLN = " + client->DLN;
	SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);
	SqlDataReader^ dbreader = cmd->ExecuteReader();

    if (dbreader->HasRows == false)
        MessageBox::Show("Ошибка считывания данных", "Ошибка!");
    else
    {
        while (dbreader->Read())
        {
            dataGridView1->Rows->Add(dbreader["Number"], dbreader["Brand"], dbreader["Model"], dbreader["Title"], dbreader["Total_price"], dbreader["Status_"]);
            z++;
        }
    }

    dbreader->Close();
    connect.conn->Close();

    return System::Void();
}

System::Void Курсачпотп::Client_menu::button_back_Click(System::Object^ sender, System::EventArgs^ e)
{
    z = 0;
    Owner->Show();
    this->Hide();
    return System::Void();
}

System::Void Курсачпотп::Client_menu::button_Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}
