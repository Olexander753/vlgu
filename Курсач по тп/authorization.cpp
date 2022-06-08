#include "authorization.h"
#include <Windows.h>
#include "Users.h"
#include "Mechanic.h"

using namespace Курсачпотп;


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	authorization^ form = gcnew authorization();
	Application::Run(form);
	return 0;
}

System::Void Курсачпотп::authorization::button_join_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ log = textBox_login->Text;
	String^ pass = textBox_password->Text;
	
	if (JoinAdmin(log, pass))
	{
		admin_menu^ adminFrorm = gcnew admin_menu;
		adminFrorm->Show();
		adminFrorm->Owner = this;
		this->Hide();
	}
	else if (JoinUser(log, pass) == 1)
	{
		main_menu^ main_menu_Form = gcnew main_menu;
		main_menu_Form->Show();
		main_menu_Form->Owner = this;
		this->Hide();
	}
	else if (JoinUser(log, pass) == 2)
	{
		Client_menu^ Client_menu_Form = gcnew Client_menu;
		Client^ client = gcnew Client;

		Connection connect;
		connect.ConnectToBD();
		connect.conn->Open();

		String^ cmdText = "select FK_DLN from Users where Login_ = '" + log + "' and Password_ = '" + pass+ "'";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

		SqlDataReader^ dbreader = cmd->ExecuteReader();

		if (dbreader->HasRows == false)
			MessageBox::Show("Ошибка считывания данных", "Ошибка!");
		else
		{
			while (dbreader->Read())
				client->DLN = Convert::ToDouble(dbreader["FK_DLN"]);
		}
		dbreader->Close();

		String^ cmdText1 = "select Full_name from Client where DLN = " + client->DLN;
		SqlCommand^ cmd1 = gcnew SqlCommand(cmdText1, connect.conn);

		SqlDataReader^ dbreader1 = cmd1->ExecuteReader();

		if (dbreader1->HasRows == false)
			MessageBox::Show("Ошибка считывания данных", "Ошибка!");
		else
		{
			while (dbreader1->Read())
				client->Full_Name = Convert::ToString(dbreader1["Full_name"]);
		}

		Client_menu_Form->DLN_label->Text = Convert::ToString(client->DLN);
		Client_menu_Form->Full_name_label->Text = client->Full_Name;
		
		Client_menu_Form->Show();
		Client_menu_Form->Owner = this;
		this->Hide();
	}
	else if (JoinUser(log, pass) == 3)
	{
		Mechanic_menu^ Mechanic_menu_Form = gcnew Mechanic_menu;
		Mechanic^ mechanic = gcnew Mechanic;

		Connection connect;
		connect.ConnectToBD();
		connect.conn->Open();

		String^ cmdText = "select FK_Mechanic_Passport_data from Users inner join Co_worker on Users.FK_PN = Co_worker.PN where Login_ =  '" + log + "' and Password_ = '" + pass + "'";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

		SqlDataReader^ dbreader = cmd->ExecuteReader();

		if (dbreader->HasRows == false)
			MessageBox::Show("Ошибка считывания данных", "Ошибка!");
		else
		{
			while (dbreader->Read())
				mechanic->P_data = Convert::ToDouble(dbreader["FK_Mechanic_Passport_data"]);
		}
		dbreader->Close();

		Mechanic_menu_Form->label_mechanic->Text = Convert::ToString(mechanic->P_data);
		Mechanic_menu_Form->Show();
		Mechanic_menu_Form->Owner = this;
		this->Hide();
	}
	else
		MessageBox::Show("Неверный логин или пароль!", "Ошибка!");
	return System::Void();
}

System::Void Курсачпотп::authorization::authorization_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	Application::Exit();
	return System::Void();
}
