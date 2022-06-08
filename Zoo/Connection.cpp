#include "Connection.h"

Zoo::Connection::Connection()
{

}

void Zoo::Connection::ConnectToBD()
{
	connection = gcnew SqlConnectionStringBuilder();
	connection->DataSource = "DESKTOP-1DCGK02\\SQLEXPRESS";
	connection->InitialCatalog = "Zoo";
	connection->IntegratedSecurity = true;

	conn = gcnew SqlConnection(Convert::ToString(connection));
}
