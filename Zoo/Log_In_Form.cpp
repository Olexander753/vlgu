#include "Log_In_Form.h"
#include <Windows.h>
#include "User.h"

using namespace Zoo;


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Log_In_Form^ form = gcnew Log_In_Form();
	Application::Run(form);
	return 0;
}

System::Void Zoo::Log_In_Form::button_log_in_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ log = textBox_login->Text;
	String^ pass = textBox_password->Text;

	if (log_in(log, pass) == "Директор")
	{
		int size_Zoo = 0;
		Menu_Director_Form^ Menu_Director_form = gcnew Menu_Director_Form;
		String^ id_der;

		Connection connect;
		connect.ConnectToBD();
		connect.conn->Open();

		String^ cmdText = "select * from User_ where Login_ = '" + log + "' and Password_ = '" + pass + "'";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

		SqlDataReader^ dbreader = cmd->ExecuteReader();

		if (dbreader->HasRows == false)
			MessageBox::Show("Ошибка считывания данных", "Ошибка!");
		else
		{
			while (dbreader->Read())
			{
				Menu_Director_form->label1->Text = Convert::ToString(dbreader["FK_Service_number_Director"]);
				id_der = Convert::ToString(dbreader["FK_Service_number_Director"]);
			}
		}

		dbreader->Close();

		String^ cmdText1 = "select * from Zoo where FK_Service_number_Director = " + id_der;
		SqlCommand^ cmd1 = gcnew SqlCommand(cmdText1, connect.conn);

		SqlDataReader^ dbreader1 = cmd1->ExecuteReader();

		if (dbreader1->HasRows == false)
			MessageBox::Show("Ошибка считывания данных", "Ошибка!");
		else
		{
			while (dbreader1->Read())
			{
				Menu_Director_form->dataGridView_Zoo->Rows->Add(dbreader1["ID"], dbreader1["Title"], dbreader1["Square_"], dbreader1["Address_"], dbreader1["Job_status"]);
				size_Zoo++;
			}
		}

		dbreader1->Close();
		connect.conn->Close();

		Menu_Director_form->Show();
		Menu_Director_form->Owner = this;
		this->Hide();
	}
	else if (log_in(log, pass) == "Сотрудник")
	{
		Menu_Employee_Form^ Menu_Employee_form = gcnew Menu_Employee_Form;
		String^ id_em;

		Connection connect;
		connect.ConnectToBD();
		connect.conn->Open();

		String^ cmdText = "select * from User_ where Login_ = '"+ log +"' and Password_ = '"+ pass +"'";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

		SqlDataReader^ dbreader = cmd->ExecuteReader();

		if (dbreader->HasRows == false)
			MessageBox::Show("Ошибка считывания данных", "Ошибка!");
		else
		{
			while (dbreader->Read())
			{
				Menu_Employee_form->label2->Text = Convert::ToString(dbreader["FK_Service_number_Employee"]);
				id_em = Convert::ToString(dbreader["FK_Service_number_Employee"]);
			}
		}

		dbreader->Close();

		String^ cmdText1 = "select * from Animal where FK_Service_number_Employee = " + id_em;
		SqlCommand^ cmd1 = gcnew SqlCommand(cmdText1, connect.conn);

		SqlDataReader^ dbreader1 = cmd1->ExecuteReader();

		if (dbreader1->HasRows == false)
			MessageBox::Show("В зоопарке отсутствуют животные привязанные к данному сотруднику!", "Ошибка!");
		else
		{
			while (dbreader1->Read())
			{
				Menu_Employee_form->dataGridView1->Rows->Add(dbreader1["ID"], dbreader1["Name_"], dbreader1["View_"], dbreader1["Feeding_status"], dbreader1["Health_status"]);
			}
		}

		dbreader1->Close();
		connect.conn->Close();

		Menu_Employee_form->Show();
		Menu_Employee_form->Owner = this;
		this->Hide();
	}
	else if (log_in(log, pass) == "Посетитель")
	{
		int size = 0;
		Menu_Visitor_Form^ Menu_Visitor_form = gcnew Menu_Visitor_Form;
		
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
				Menu_Visitor_form->dataGridView1->Rows->Add(dbreader["Title"], dbreader["Address_"], dbreader["Square_"], dbreader["Job_status"]);
				size++;
			}
		}

		dbreader->Close();
		connect.conn->Close();

		Menu_Visitor_form->Show();
		Menu_Visitor_form->Owner = this;
		this->Hide();
	}
	else
	{
		MessageBox::Show("Неверный логин или пароль!", "Ошибка!");
	}
    return System::Void();
}

System::Void Zoo::Log_In_Form::linkLabel_sing_up_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
{
	Register_Form^ Register_form = gcnew Register_Form;
	Register_form->Show();
    return System::Void();
}

System::Void Zoo::Log_In_Form::Log_In_Form_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	Application::Exit();
	return System::Void();
}
