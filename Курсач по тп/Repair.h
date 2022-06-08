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

	ref class Repair
	{
	public:
		Repair();

		static int id;
		static property int ID
		{
			int get()
			{
				return id;
			}

			void set(int value)
			{
				id = value;
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

		public:ListBox::ObjectCollection^ FillComndoBox_Repairs()
		{
			ListBox^ ListWithTitls = gcnew ListBox();

			Connection connect;
			connect.ConnectToBD();
			connect.conn->Open();

			String^ cmdText = "select * from Type_repair";
			SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

			SqlDataReader^ dbreader = cmd->ExecuteReader();

			Repair^ repair = gcnew Repair();

			int k = 1;
			while (dbreader->Read())
			{
				repair->ID = Convert::ToInt32(dbreader["ID"]->ToString());
				repair->Name = (dbreader["Title"]->ToString());
				ListWithTitls->Items->Add(String::Format("{0}-{1}", repair->ID, repair->Name));
			}
			return ListWithTitls->Items;

			dbreader->Close();
			connect.conn->Close();
		}

			 
		public:ListBox::ObjectCollection^ FillComndoBox_Repairs_Update(Repair^ repair)
		{
			ListBox^ ListWithTitls = gcnew ListBox();

			ListWithTitls->Items->Add(String::Format("{0}-{1}", repair->ID, repair->Name));

			Connection connect;
			connect.ConnectToBD();
			connect.conn->Open();

			String^ cmdText = "select * from Type_repair";
			SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

			SqlDataReader^ dbreader = cmd->ExecuteReader();

			Repair^ repair1 = gcnew Repair();

			int k = 1;
			while (dbreader->Read())
			{
				repair1->ID = Convert::ToInt32(dbreader["ID"]->ToString());
				repair1->Name = (dbreader["Title"]->ToString());
				ListWithTitls->Items->Add(String::Format("{0}-{1}", repair1->ID, repair1->Name));
			}
			return ListWithTitls->Items;

			dbreader->Close();
			connect.conn->Close();
		}
	};
}