#pragma once
#include <iostream>

using namespace std;

template<class T>
T sort1(T* arr, int size)
{
    if (size < 2) return 0;

    int temp,// Временная переменная для хранения значения элемента сортируемого массива
        item;// индекс предыдущего элемента
    for (int counter = 1; counter < size; counter++)
    {
        temp = arr[counter];// Инициализируем временную переменную текущим значением элемента массива
        item = counter - 1;// запоминаем индекс предыдущего элемента массива
        while (item >= 0 && arr[item] > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
        {
            arr[item + 1] = arr[item];// перестановка элементов массива
            arr[item] = temp;
            item--;
        }
    }
}

template<class T>
T sort2(T* arr, int size)
{
    if (size < 2) return 0;

    int temp,// Временная переменная для хранения значения элемента сортируемого массива
        item;// индекс предыдущего элемента
    for (int counter = 1; counter < size; counter++)
    {
        temp = arr[counter];// Инициализируем временную переменную текущим значением элемента массива
        item = counter - 1;// запоминаем индекс предыдущего элемента массива
        while (item >= 0 && arr[item] < temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
        {
            arr[item + 1] = arr[item];// перестановка элементов массива
            arr[item] = temp;
            item--;
        }
    }
}