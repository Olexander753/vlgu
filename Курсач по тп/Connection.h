#pragma once

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

	ref class Connection
	{
	public:
		Connection();

		SqlConnection^ conn;
		SqlConnectionStringBuilder^ connection;

		void ConnectToBD()
		{
			connection = gcnew SqlConnectionStringBuilder();
			connection->DataSource = "DESKTOP-1DCGK02\\SQLEXPRESS";
			connection->InitialCatalog = "Curse";
			connection->IntegratedSecurity = true;

			conn = gcnew SqlConnection(Convert::ToString(connection));
		}
	};
}