#include "Menu_Employee_Form.h"
#include "Add_Animal_Form.h"
#include "Connection.h"
#include "Animal.h"
#include "Update_Animal_Form.h"

System::Void Zoo::Menu_Employee_Form::button_Add_Click(System::Object^ sender, System::EventArgs^ e)
{
    Add_Animal_Form^ Add_Animal_form = gcnew Add_Animal_Form;

    Connection connect;
    connect.ConnectToBD();
    connect.conn->Open();

    String^ Zoo_ID;
    String^ Em_ID = label2->Text;

    String^ cmdText = "select * from Employee where Service_number =" + Em_ID;
    SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

    SqlDataReader^ dbreader = cmd->ExecuteReader();

    Animal^ animal = gcnew Animal;

    while (dbreader->Read())
    {
        Zoo_ID = Convert::ToString(dbreader["FK_ID_Zoo"]);
    }

    dbreader->Close();
    connect.conn->Close();

    Add_Animal_form->label5->Text = Zoo_ID; 
    Add_Animal_form->label6->Text = Em_ID;
    Add_Animal_form->Show();
    return System::Void();
}

System::Void Zoo::Menu_Employee_Form::button_Update_Click(System::Object^ sender, System::EventArgs^ e)
{
    Update_Animal_Form^ Update_Animal_form = gcnew Update_Animal_Form;

    if (dataGridView1->SelectedRows->Count != 1)
    {
        MessageBox::Show("Выберите одну строку для изменения", "Внимание!");
        return;
    }
    int index = dataGridView1->SelectedRows[0]->Index;

    Update_Animal_form->textBox_Name->Text= Convert::ToString(dataGridView1->Rows[index]->Cells[1]->Value->ToString());
    Update_Animal_form->textBox_View->Text = Convert::ToString(dataGridView1->Rows[index]->Cells[2]->Value->ToString());
    Update_Animal_form->textBox_Status_Feeding->Text = Convert::ToString(dataGridView1->Rows[index]->Cells[3]->Value->ToString());
    Update_Animal_form->textBox_Status_helth->Text = Convert::ToString(dataGridView1->Rows[index]->Cells[4]->Value->ToString());
    Update_Animal_form->label5->Text = Convert::ToString(dataGridView1->Rows[index]->Cells[0]->Value->ToString());
    Update_Animal_form->Show();
    return System::Void();
}

System::Void Zoo::Menu_Employee_Form::button_Delete_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        if (dataGridView1->SelectedRows->Count != 1)
        {
            MessageBox::Show("Выберите одну строку для изменения", "Внимание!");
            return;
        }

        int index = dataGridView1->SelectedRows[0]->Index;

        Animal^ animal = gcnew Animal;
        animal->ID = Convert::ToInt32(dataGridView1->Rows[index]->Cells[0]->Value->ToString());

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText = "DELETE FROM Animal WHERE ID = '" + animal->ID + "'";
        SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

        if (cmd->ExecuteNonQuery() < 1)
            MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
        else
        {
            MessageBox::Show("Данные изменены!", "Готово!");
            dataGridView1->Rows->RemoveAt(index);
        }

        connect.conn->Close();
        return System::Void();
    }
    catch (SqlException^ ex)
    {
        String^ Error = ex->Errors->ToString();
        MessageBox::Show("Проверьте правильность введённыйх данных!\n " + ex + "", "Ошибка!");
        return System::Void();
    }
}

System::Void Zoo::Menu_Employee_Form::button_Feed_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        if (dataGridView1->SelectedRows->Count != 1)
        {
            MessageBox::Show("Выберите одну строку для изменения", "Внимание!");
            return;
        }
        int index = dataGridView1->SelectedRows[0]->Index;

        Animal^ animal = gcnew Animal;

        animal->ID = Convert::ToInt32(dataGridView1->Rows[index]->Cells[0]->Value->ToString());

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText1 = "select * from Food where FK_ID_Animal = " + animal->ID;
        SqlCommand^ cmd1 = gcnew SqlCommand(cmdText1, connect.conn);
        
        SqlDataReader^ dbreader = cmd1->ExecuteReader();

        int qty;
        if (dbreader->HasRows == false)
        {
            MessageBox::Show("Отсутствует корм для данного животного!", "Ошибка!");
            return System::Void();
        }
        else
        {
            while (dbreader->Read())
            {
                qty = Convert::ToInt32(dbreader["Qty"]);
            }
        }

        if (qty < 1)
        {
            MessageBox::Show("Недостаточно корма!", "Ошибка!");
            return System::Void();
        }

        dbreader->Close();

        String^ cmdText = "UPDATE Animal Set Feeding_status = 'Покормлен' WHERE ID = " + animal->ID+"; UPDATE Food Set Qty = (select Qty from Food where FK_ID_Animal = " + animal->ID + ") -1  WHERE FK_ID_Animal = " + animal->ID + "";
        SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

        if (cmd->ExecuteNonQuery() < 2)
        {
            MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
        }
        else
        {
            MessageBox::Show("Животное покормленно!", "Готово!");
            dataGridView1->Rows[index]->Cells[3]->Value = "Покормлен";

        }

        connect.conn->Close();

        return System::Void();
    }
    catch (SqlException^ ex)
    {
        String^ Error = ex->Errors->ToString();
        MessageBox::Show("Проверьте правильность введённыйх данных!\n" + ex + "", "Ошибка!");
        return System::Void();
    }
}

System::Void Zoo::Menu_Employee_Form::button_Treat_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        if (dataGridView1->SelectedRows->Count != 1)
        {
            MessageBox::Show("Выберите одну строку для изменения", "Внимание!");
            return;
        }
        int index = dataGridView1->SelectedRows[0]->Index;

        Animal^ animal = gcnew Animal;

        animal->ID = Convert::ToInt32(dataGridView1->Rows[index]->Cells[0]->Value->ToString());
        animal->Health_status = dataGridView1->Rows[index]->Cells[4]->Value->ToString();

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText = "UPDATE Animal Set Health_status = '" + animal->Health_status +"' WHERE ID = " + animal->ID;
        SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

        if (cmd->ExecuteNonQuery() != 1)
        {
            MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
        }
        else
        {
            MessageBox::Show("Данные добалены!", "Готово!");
            dataGridView1->Rows[index]->Cells[4]->Value = animal->Health_status;

        }

        connect.conn->Close();

        return System::Void();
    }
    catch (SqlException^ ex)
    {
        String^ Error = ex->Errors->ToString();
        MessageBox::Show("Проверьте правильность введённыйх данных!\n" + ex + "", "Ошибка!");
        return System::Void();
    }
}

System::Void Zoo::Menu_Employee_Form::Menu_Employee_Form_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

System::Void Zoo::Menu_Employee_Form::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        if (dataGridView1->SelectedRows->Count != 1)
        {
            MessageBox::Show("Выберите одну строку для изменения", "Внимание!");
            return;
        }
        int index = dataGridView1->SelectedRows[0]->Index;

        Animal^ animal = gcnew Animal;

        animal->ID = Convert::ToInt32(dataGridView1->Rows[index]->Cells[0]->Value->ToString());

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText = "UPDATE Animal Set Feeding_status = 'Голоден' WHERE ID = " + animal->ID;
        SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

        if (cmd->ExecuteNonQuery() != 1)
        {
            MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
        }
        else
        {
            MessageBox::Show("Данные добалены!", "Готово!");
            dataGridView1->Rows[index]->Cells[3]->Value = "Голоден";

        }

        connect.conn->Close();

        return System::Void();
    }
    catch (SqlException^ ex)
    {
        String^ Error = ex->Errors->ToString();
        MessageBox::Show("Проверьте правильность введённыйх данных!\n" + ex + "", "Ошибка!");
        return System::Void();
    }
}

System::Void Zoo::Menu_Employee_Form::обновитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    int size = 0;
    size = dataGridView1->RowCount - 1;
    while (size != 0)
    {
        dataGridView1->Rows->RemoveAt(size - 1);
        size = size - 1;
    }
    try
    {
        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ Em_ID = label2->Text;

        String^ cmdText = "select * from Animal where FK_Service_number_Employee = " + Em_ID;
        SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

        SqlDataReader^ dbreader = cmd->ExecuteReader();

        if (dbreader->HasRows == false)
            MessageBox::Show("Ошибка считывания данных", "Ошибка!");
        else
        {
            while (dbreader->Read())
            {
                dataGridView1->Rows->Add(dbreader["ID"], dbreader["Name_"], dbreader["View_"], dbreader["Feeding_status"], dbreader["Health_status"]);
            }
        }

        dbreader->Close();
        connect.conn->Close();

        return System::Void();
    }
    catch (SqlException^ ex)
    {
        String^ Error = ex->Errors->ToString();
        MessageBox::Show("Проверьте правильность введённыйх данных!\n" + ex + "", "Ошибка!");
        return System::Void();
    }
}
