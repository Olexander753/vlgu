#pragma once
#include "Connection.h"

namespace Курсачпотп{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Data;
	using namespace Data::SqlClient;

	ref class Mechanic
	{
	public:
		Mechanic();

		static String^ login;
		static property String^ Login
		{
			String^ get()
			{
				return login;
			}

			void set(String^ value)
			{
				login = value;
			}
		}

		static String^ password;
		static property String^ Password
		{
			String^ get()
			{
				return password;
			}

			void set(String^ value)
			{
				password = value;
			}
		}

		static int pn;
		static property int PN
		{
			int get()
			{
				return pn;
			}

			void set(int value)
			{
				pn = value;
			}
		}

		static String^ full_name;
		static property String^ Full_name
		{
			String^ get()
			{
				return full_name;
			}

			void set(String^ value)
			{
				full_name = value;
			}
		}

		static String^ qualification;
		static property String^ Qualification
		{
			String^ get()
			{
				return qualification;
			}

			void set(String^ value)
			{
				qualification = value;
			}
		}

		static double p_data;
		static property double P_data
		{
			double get()
			{
				return p_data;
			}

			void set(double value)
			{
				p_data = value;
			}
		}

		static double p_number;
		static property double P_number
		{
			double get()
			{
				return p_number;
			}

			void set(double value)
			{
				p_number = value;
			}
		}

		public:ListBox::ObjectCollection^ FillComndoBox_Mechanics()
		{
			ListBox^ ListWithName = gcnew ListBox();

			Connection connect;
			connect.ConnectToBD();
			connect.conn->Open();

			String^ cmdText = "select Full_name from Mechanic";
			SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

			SqlDataReader^ dbreader = cmd->ExecuteReader();

			Mechanic^ mechanic = gcnew Mechanic();

			int k = 1;
			while (dbreader->Read())
			{
				mechanic->Full_name = (dbreader["Full_name"]->ToString());
				ListWithName->Items->Add(String::Format(mechanic->Full_name));

			}
			return ListWithName->Items;

			dbreader->Close();
			connect.conn->Close();
		}

		public:ListBox::ObjectCollection^ FillComndoBox_Mechanics_Update(Mechanic^ mechanic1)
		{
			ListBox^ ListWithName = gcnew ListBox();

			ListWithName->Items->Add(String::Format(mechanic1->Full_name));

			Connection connect;
			connect.ConnectToBD();
			connect.conn->Open();

			String^ cmdText = "select Full_name from Mechanic";
			SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

			SqlDataReader^ dbreader = cmd->ExecuteReader();

			Mechanic^ mechanic2 = gcnew Mechanic();

			int k = 1;
			while (dbreader->Read())
			{
				mechanic2->Full_name = (dbreader["Full_name"]->ToString());
				ListWithName->Items->Add(String::Format(mechanic2->Full_name));

			}
			return ListWithName->Items;

			dbreader->Close();
			connect.conn->Close();
		}
	};
}