#pragma once
#include "Connection.h"

namespace Курсачпотп {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Data;
	using namespace Data::SqlClient;
	
	ref class Detal
	{
	public:
		Detal();

		static int vender_code;
		static property int Vender_code
		{
			int get()
			{
				return vender_code;
			}

			void set(int value)
			{
				vender_code = value;
			}
		}

		static String^ name;
		static property String^ Name
		{
			String^ get()
			{
				return name;
			}
			void set(String^ value)
			{
				name = value;
			}
		}

		static Double price;
		static property Double Price
		{
			Double get()
			{
				return price;
			}

			void set(Double value)
			{
				price = value;
			}
		}

		static int quantity;
		static property int Quantity
		{
			int get()
			{
				return quantity;
			}

			void set(int value)
			{
				quantity = value;
			}
		}

	public:ListBox::ObjectCollection^ FillComndoBox_Detals()
	{
		ListBox^ ListWithTitls = gcnew ListBox();

		Connection connect;
		connect.ConnectToBD();
		connect.conn->Open();

		String^ cmdText = "select * from Detail";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

		SqlDataReader^ dbreader = cmd->ExecuteReader();

		Detal^ detal = gcnew Detal();

		String^ qwe = "\0";
		ListWithTitls->Items->Add(String::Format(qwe));

		int k = 1;
		while (dbreader->Read())
		{
			detal->Vender_code = Convert::ToInt32(dbreader["ID"]->ToString());
			detal->Name = (dbreader["Title"]->ToString());

			ListWithTitls->Items->Add(String::Format("{0}-{1}", detal->Vender_code ,detal->Name));

		}
		return ListWithTitls->Items;

		dbreader->Close();
		connect.conn->Close();
	}

	public:ListBox::ObjectCollection^ FillComndoBox_Detals_Update(Detal^ detal1)
	{
		ListBox^ ListWithTitls = gcnew ListBox();

		ListWithTitls->Items->Add(String::Format("{0}-{1}", detal1->Vender_code, detal1->Name));

		Connection connect;
		connect.ConnectToBD();
		connect.conn->Open();

		String^ cmdText = "select * from Detail";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

		SqlDataReader^ dbreader = cmd->ExecuteReader();

		Detal^ detal2 = gcnew Detal();

		int k = 1;
		while (dbreader->Read())
		{
			detal2->Vender_code = Convert::ToInt32(dbreader["ID"]->ToString());
			detal2->Name = (dbreader["Title"]->ToString());

			ListWithTitls->Items->Add(String::Format("{0}-{1}", detal2->Vender_code, detal2->Name));

		}
		return ListWithTitls->Items;

		dbreader->Close();
		connect.conn->Close();
	}
	};
}

