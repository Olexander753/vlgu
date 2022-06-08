#pragma once
#include "Connection.h"
#include "User.h"

namespace Zoo
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Data;
	using namespace Data::SqlClient;

	String^ log_in(String^ log, String^ pass)
	{
		Connection connect;
		connect.ConnectToBD();
		connect.conn->Open();

		String^ cmdText = "SELECT * FROM User_";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);
		SqlDataReader^ dbreader = cmd->ExecuteReader();

		User^ user = gcnew User();

		while (dbreader->Read())
		{
			user->Login = (dbreader["Login_"]->ToString());
			user->Password = (dbreader["Password_"]->ToString());
			user->Role = (dbreader["Role_"]->ToString());

			if (log == user->Login && pass == user->Password)
				return user->Role;
		}
		dbreader->Close();
		connect.conn->Close();

		String^ s = "";
		return s;
	}
}
