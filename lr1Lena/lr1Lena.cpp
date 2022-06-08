#include <iostream>
#include "Data.h"

int main()
{
    setlocale(LC_ALL, "RUS");
    try
    {
        Data a = Data(20, 10, 2019, "Среда");
        cout << a.week() << endl;

        //Data b = Data(20, 13, 2019, "Среда");
        // проверка работы исключения месяца
        // 
        //Data c = Data(32, 10, 2019, "Среда");
        // проверка работы исключения числа
        // 
        //Data d = Data(20, 10, -1, "Среда");
        // проверка работы исключения года
        // 
        //Data e = Data(20, 10, 2019, "Средdа");
        // проверка работы исключения дня недели
        // 
        //Data f; cout << f.week() << endl;
        //проверка работы исключения обращения к пустому элементу
    }
    catch (const char* error) {
        std::cerr << error;
        std::exit(-231);
    }
}