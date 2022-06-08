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
	ref class Food
	{
	public:
		Food();

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

		static String^ title;
		static property String^ Title
		{
			String^ get()
			{
				return title;
			}

			void set(String^ value)
			{
				title = value;
			}
		}

		static int qty;
		static property int Qty
		{
			int get()
			{
				return qty;
			}

			void set(int value)
			{
				qty = value;
			}
		}
	};
}