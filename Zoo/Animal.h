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
	ref class Animal
	{
	public:
		Animal();

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

		static String^ health_status;
		static property String^ Health_status
		{
			String^ get()
			{
				return health_status;
			}

			void set(String^ value)
			{
				health_status = value;
			}
		}

		static String^ feed_status;
		static property String^ Feed_status
		{
			String^ get()
			{
				return feed_status;
			}

			void set(String^ value)
			{
				feed_status = value;
			}
		}

		static String^ view;
		static property String^ View
		{
			String^ get()
			{
				return view;
			}

			void set(String^ value)
			{
				view = value;
			}
		}
	};
}