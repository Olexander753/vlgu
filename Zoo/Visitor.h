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
	ref class Visitor
	{
	public:
		Visitor();

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

		static double phone_number;
		static property double Phone_number
		{
			double get()
			{
				return phone_number;
			}

			void set(double value)
			{
				phone_number = value;
			}
		}
	};
}