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

	ref class Users
	{
	public:
		Users();

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

		static String^ role;
		static property String^ Role
		{
			String^ get()
			{
				return role;
			}

			void set(String^ value)
			{
				role = value;
			}
		}
	};
}