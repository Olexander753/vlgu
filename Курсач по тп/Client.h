#pragma once

namespace Курсачпотп {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Data;
	using namespace Data::SqlClient;
	ref class Client
	{
	public:
		Client();

		static double dln;
		static property double DLN
		{
			double get()
			{
				return dln;
			}

			void set(double value)
			{
				dln = value;
			}
		}

		static String^ full_name;
		static property String^ Full_Name
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

		static double p_number;
		static property double P_Number
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
	};
}