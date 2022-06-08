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

	ref class Director
	{
	public:
		Director();

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

		static double passport_data;
		static property double Passport_data
		{
			double get()
			{
				return passport_data;
			}

			void set(double value)
			{
				passport_data = value;
			}
		}

		static int service_number;
		static property int Service_number
		{
			int get()
			{
				return service_number;
			}

			void set(int value)
			{
				service_number = value;
			}
		}
	};
}