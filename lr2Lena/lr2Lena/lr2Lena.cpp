#include <iostream>
#include "Sort.h"
#include "Country.h"
#include "Set.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "RUS");
    try
    {
        //Первое 3адание
        /*
        int n;
        cout << "Введите N: " << endl;
        cin >> n;
        int *a = new int[n];  //cо3дание массива
        for (int i = 0; i < n; i++) // инициали3ация массива
        {
            a[i] = rand() % 20 + 10;
            cout << a[i] << " ";
        }
        sort(a, n); // сортировка
        cout << endl << "Результат: " << endl;
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        */

        //Второе 3адание
        Country a("Россия", "смешанная республика", 17130000);
        Country b("США", "демократия", 9834000);
        Country c("Китай", "однопартийная парламентская республика", 9597000);

        Set <Country> set1;
        Set <Country> set2;

        //set1.input(a);   //добавление элемента в множество
        //set1.input(b);
        //set1.input(c); //проверка на переполнение

        set2.input(b);
        set2.input(c);

        set1.print();
        set2.print();

        cout << set1.power() << endl << endl; //вывод мощности множества

        set1* set2;                           // пересечение множеств

        set2 + c;                             //добавление элемента в множество
        set2.print();
        
    }
    catch (const char* error)
    {
        cerr << error;
        exit(-231);
    }
    system("pause");
    return 0;
}