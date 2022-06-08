#include <iostream>
#include "Array.h"
#include "complex.h"

int main()
{
    try
    {
        complex a(4, 6);
        complex b(3, 2);
        complex c(1, 7);

        Array <complex> arr1;
        Array <complex> arr2;
        arr1.input(a);
        arr1.input(b);
        arr1.input(c);
        arr1.input(c);
        arr2.input(b);
        arr2.input(a);


        arr1.print();
        arr2.print();

        arr1 - arr2;
        arr1.print();

        arr1 - 1;
        arr1.print();

        arr2[3];
    }
    catch (const char* error)
    {
        cout << error << endl;
        exit(-231);
    }
}
