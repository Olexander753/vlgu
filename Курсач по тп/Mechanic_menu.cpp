#include "Mechanic_menu.h"

int y = 0;

System::Void Курсачпотп::Mechanic_menu::button_Execute_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        if (dataGridView1->SelectedRows->Count != 1)
        {
            MessageBox::Show("Выберите одну строку для изменения", "Внимание!");
            return;
        }
        int index = dataGridView1->SelectedRows[0]->Index;

        Request^ request = gcnew Request;

        request->ID = Convert::ToInt32(dataGridView1->Rows[index]->Cells[0]->Value->ToString());
        request->Number = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
        request->Title = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
        request->Status = dataGridView1->Rows[index]->Cells[3]->Value->ToString();

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText_rollback;
        String^ cmdText_commit;

        String^ cmdText = "begin tran UPDATE Repair Set Status_ = 'Готово' WHERE ID = " + request->ID;
        cmdText_rollback = cmdText + "rollback";
        SqlCommand^ cmd = gcnew SqlCommand(cmdText_rollback, connect.conn);

        if (cmd->ExecuteNonQuery() != 1)
        {
            MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
        }
        else
        {
            cmdText_commit = cmdText + "commit";
            SqlCommand^ cmd1 = gcnew SqlCommand(cmdText_commit, connect.conn);
            if (cmd1->ExecuteNonQuery() == 1)
            {
                MessageBox::Show("Данные добалены!", "Готово!");
                request->Status = "Готово";
                dataGridView1->Rows->RemoveAt(index);
                dataGridView1->Rows->Add(request->ID, request->Number, request->Title, request->Status);
            }

        }
        connect.conn->Close();
        return System::Void();
    }
    catch (SqlException^ ex)
    {
        String^ Error = ex->Errors->ToString();
        MessageBox::Show("Проверьте правильность введённыйх данных!", "Ошибка!");
        return System::Void();
    }
}

System::Void Курсачпотп::Mechanic_menu::button_Update_Click(System::Object^ sender, System::EventArgs^ e)
{
    while (y != 0)
    {
        dataGridView1->Rows->RemoveAt(y - 1);
        y = y - 1;
    }

    Mechanic^ mechanic = gcnew Mechanic;

    mechanic->P_data = Convert::ToDouble(label_mechanic->Text);

    Connection connect;
    connect.ConnectToBD();
    connect.conn->Open();

    String^ cmdText = "select Repair.ID, Repair.FK_Number, Type_repair.Title, Repair.Status_ from Repair inner join Type_repair on Repair.FK_ID_repair = Type_repair.ID where FK_Passport_data = " + mechanic->P_data;
    SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

    SqlDataReader^ dbreader = cmd->ExecuteReader();

    if (dbreader->HasRows == false)
        MessageBox::Show("Ошибка считывания данных", "Ошибка!");
    else
    {
        while (dbreader->Read())
        {
            dataGridView1->Rows->Add(dbreader["ID"], dbreader["FK_Number"], dbreader["Title"], dbreader["Status_"]);
            y++;
        }
    }

    dbreader->Close();
    connect.conn->Close();
    return System::Void();
}

System::Void Курсачпотп::Mechanic_menu::button_Back_Click(System::Object^ sender, System::EventArgs^ e)
{
    y = 0;
    Owner->Show();
    this->Hide();
    return System::Void();
}

System::Void Курсачпотп::Mechanic_menu::button_Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}
