namespace Zoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Data;
	using namespace Data::SqlClient;

	ref class Zoopark
	{
	public:
		Zoopark();


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
	};
}
