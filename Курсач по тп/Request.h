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
	ref class Request
	{
	public:
		Request();

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

		static String^ number;
		static property String^ Number
		{
			String^ get()
			{
				return number;
			}
			void set(String^ value)
			{
				number = value;
			}
		}

		static String^ brand;
		static property String^ Brand
		{
			String^ get()
			{
				return brand;
			}
			void set(String^ value)
			{
				brand = value;
			}
		}

		static String^ model;
		static property String^ Model
		{
			String^ get()
			{
				return model;
			}
			void set(String^ value)
			{
				model = value;
			}
		}

		static String^ full_name_;
		static property String^ Full_name_
		{
			String^ get()
			{
				return full_name_;
			}
			void set(String^ value)
			{
				full_name_ = value;
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

		static String^ title_;
		static property String^ Title_
		{
			String^ get()
			{
				return title_;
			}
			void set(String^ value)
			{
				title_ = value;
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

		static String^ date;
		static property String^ Date
		{
			String^ get()
			{
				return date;
			}
			void set(String^ value)
			{
				date = value;
			}
		}

		static Double total_price;
		static property Double Total_Price
		{
			Double get()
			{
				return total_price;
			}

			void set(double value)
			{
				total_price = value;
			}
		}

		static String^ status;
		static property String^ Status
		{
			String^ get()
			{
				return status;
			}
			void set(String^ value)
			{
				status = value;
			}
		}


	};
}