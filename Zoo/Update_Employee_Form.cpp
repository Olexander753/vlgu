#include "Update_Employee_Form.h"
#include <iostream>

System::Void Zoo::Update_Employee_Form::button_Update_Click(System::Object^ sender, System::EventArgs^ e)
{
    setlocale(LC_ALL, "RUS");
    try
    {
        if (textBox_Full_name->Text == nullptr ||
            textBox_Passport_data->Text == nullptr ||
            textBox_Login == nullptr ||
            textBox_Password == nullptr)
        {
            MessageBox::Show("Введены не все данные!", "Внимание!");
            return;
        }

        Employee^ employee = gcnew Employee;
        User^ user = gcnew User;

        employee->Full_name = textBox_Full_name->Text;
        employee->Passport_data = Convert::ToDouble(textBox_Passport_data->Text);
        employee->Service_number = Convert::ToInt32(label6->Text);

        String^ Zoo_ID = label7->Text;

        user->Login = textBox_Login->Text;
        user->Password = textBox_Password->Text;

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText1;
        String^ cmdText2;

        String^ cmdText = "begin tran UPDATE Employee set Full_name = '"+employee->Full_name+"', Passport_data = "+employee->Passport_data+" , FK_ID_Zoo = "+Zoo_ID+" where Service_number = "+employee->Service_number+"; UPDATE User_ set Login_ = '"+user->Login+"', Password_ = '"+user->Password+"' where FK_Service_number_Employee = "+employee->Service_number;
        cmdText1 = cmdText + " rollback";
        SqlCommand^ cmd = gcnew SqlCommand(cmdText1, connect.conn);

        if (cmd->ExecuteNonQuery() != 2)
        {
            MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
        }
        else
        {
            cmdText2 = cmdText + " commit";
            SqlCommand^ cmd1 = gcnew SqlCommand(cmdText2, connect.conn);
            if (cmd1->ExecuteNonQuery() == 2)
                MessageBox::Show("Данные добалены!", "Готово!");
        }

        connect.conn->Close();
        this->Hide();

        return System::Void();

        return System::Void();
    }
    catch (SqlException^ ex)
    {
        String^ Error = ex->Errors->ToString();
        MessageBox::Show("Проверьте правильность введённыйх данных!\n " + ex + "", "Ошибка!");
        return System::Void();
    }
}
