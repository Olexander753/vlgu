#pragma once
namespace Zoo {
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

		void ConnectToBD();
	};
}