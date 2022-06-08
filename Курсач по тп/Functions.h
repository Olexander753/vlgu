#pragma once
#include "Users.h"
#include "Connection.h"
#include "Users.h"

namespace Курсачпотп 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Data;
	using namespace Data::SqlClient;


	int JoinUser(String^ login, String^ password)
	{
		Connection connect;
		connect.ConnectToBD();
		connect.conn->Open();

		String^ cmdText = "SELECT * FROM Users";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);
		SqlDataReader^ dbreader = cmd->ExecuteReader();

		Users^ user = gcnew Users();
		
		bool join = false;
		int q = 0;

		while (dbreader->Read())
		{
			user->Login = (dbreader["Login_"]->ToString());
			user->Password = (dbreader["Password_"]->ToString());
			user->Role = (dbreader["Role_"]->ToString());

			if (login == user->Login && password == user->Password)
			{
				if (user->Role == "Менеджер")
					q = 1;
				else if (user->Role == "Клиент")
					q = 2;
				else if (user->Role == "Механик")
					q = 3;
				break;
			}
		}
		dbreader->Close();
		connect.conn->Close();

		return q;
	}

	bool JoinAdmin(String^ login, String^ password)
	{
		if (login == "1" && password == "1")
			return true;
		else
			return false;
	}
}