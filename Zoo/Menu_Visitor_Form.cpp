#include "Menu_Visitor_Form.h"

System::Void Zoo::Menu_Visitor_Form::Menu_Visitor_Form_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    Owner->Show();
    this->Hide();
    return System::Void();
}
