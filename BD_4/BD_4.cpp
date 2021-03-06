#undef UNICODE
#include <windows.h>
#include <odbcinst.h>
#include <sql.h>
#include <sqlext.h>
#include <ctype.h>
#include <string>
#include <iostream>

using namespace std;

SQLCHAR connectionStringDSN[256] = "DSN=qwe; UID=u1; PWD=u1;";
SQLCHAR connectionStringDriver[256] ="DRIVER={SQL Server};SERVER=DESKTOP-1DCGK02\\SQLEXPRESS;UID=u1;PWD=u1;DATABASE=lr4;";

void errorMessage(const char* s)
{
    cout << "*** Error ***" << s << endl;
}

void Message(const char* s)
{
    cout << s << endl;
}

void DoSelect(SQLCHAR connectionString[256])
{
    HENV hEnv;
    HDBC hDbc;
    HSTMT hStmt = SQL_NULL_HSTMT;
    RETCODE rc;
    SQLSMALLINT cbOutConStr = 0;

    SQLCHAR outConnectionString[256];
    SQLAllocEnv(&hEnv);
    SQLAllocConnect(hEnv, &hDbc);
    rc = SQLDriverConnect(hDbc, NULL, connectionString, SQL_NTS, outConnectionString, sizeof(outConnectionString), &cbOutConStr, SQL_DRIVER_COMPLETE);

    if (!(rc == SQL_SUCCESS) && !(rc == SQL_SUCCESS_WITH_INFO))
    {
        errorMessage("Error SQLDriverConnect");
        return;
    }

    SQLHSTMT hstmt;
    rc = SQLAllocStmt(hDbc, &hstmt);
    SQLCHAR command[256] = "select ID, Title, Price from Repair; \0";
    rc = SQLExecDirect(hstmt, command, SQL_NTS);

    SQLINTEGER ID;
    SQLCHAR Title[256];
    SQLFLOAT Price;
    SQLINTEGER cbID, cbTitle, cbPrice;

    if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)
    {
        SQLBindCol(hstmt, 1, SQL_C_ULONG, &ID, 0, &cbID);
        SQLBindCol(hstmt, 2, SQL_C_CHAR, &Title, 256, &cbTitle);
        SQLBindCol(hstmt, 3, SQL_C_DOUBLE, &Price, 0, &cbPrice);

        while (TRUE)
        {
            rc = SQLFetch(hstmt);
            if (rc == SQL_ERROR)
                errorMessage("Error in the fetch");
            if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)
                cout << ID << " " << Title << " " << Price << endl;
            else
                break;
        }

        SQLDisconnect(hDbc);
        SQLFreeConnect(hDbc);
        SQLFreeEnv(hEnv);
    }
    else
        errorMessage("Exec SQL error");
}


void ListDSN()
{
    const short SQL_MAX_DSN_LENGTH_ = SQL_MAX_DSN_LENGTH;

    UCHAR szDSN[SQL_MAX_DSN_LENGTH + 1];
    UCHAR szDescription[256];
    short wDSNLen;
    SQLSMALLINT wDesLen;
    int retCode;
    SQLHENV hEnv = NULL;
    string DSNName;
    string resultString;
    string Descr;

    SQLAllocEnv(&hEnv);

    retCode = SQLDataSources(hEnv, SQL_FETCH_FIRST, szDSN, SQL_MAX_DSN_LENGTH_ + 1, &wDSNLen, szDescription, 256, &wDesLen);

    while (retCode == SQL_SUCCESS || retCode == SQL_SUCCESS_WITH_INFO)
    {
        DSNName = (string)((char*)szDSN);
        Descr = (string)((char*)szDescription);
        resultString += DSNName;
        resultString += "\n";

        retCode = SQLDataSources(hEnv, SQL_FETCH_NEXT, szDSN, SQL_MAX_DSN_LENGTH_ + 1, &wDSNLen, szDescription, 256, &wDesLen);
    }

    SQLFreeEnv(hEnv);
    Message(resultString.c_str());
}

void ShowMenu()
{
    int choice = 0;
    bool done = false;
    do
    {
        cout << "\n *** MENU *** " << endl;
        cout << "0 - output" << endl;
        cout << "1 - list all DSN" << endl;
        cout << "2 - select (using DNS)" << endl;
        cout << "3 - select (using driver directly)" << endl;
        cout << "Choice : ";
        cin >> choice;
        switch (choice)
        {
        default: done = true; break;
        case 1: ListDSN(); break;
        case 2: DoSelect(connectionStringDSN); break;
        case 3: DoSelect(connectionStringDriver); break;
        }
    } while (!done);
}

int main()
{
    ShowMenu();
    return 0;
}