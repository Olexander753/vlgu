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

	ref class Manager
	{
	public:
		Manager();

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
	};
}