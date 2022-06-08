#pragma once
#include <iostream>

using namespace std;

template<class T>
T sort1(T* arr, int size)
{
    if (size < 2) return 0;

    int temp,// ��������� ���������� ��� �������� �������� �������� ������������ �������
        item;// ������ ����������� ��������
    for (int counter = 1; counter < size; counter++)
    {
        temp = arr[counter];// �������������� ��������� ���������� ������� ��������� �������� �������
        item = counter - 1;// ���������� ������ ����������� �������� �������
        while (item >= 0 && arr[item] > temp) // ���� ������ �� ����� 0 � ���������� ������� ������� ������ ��������
        {
            arr[item + 1] = arr[item];// ������������ ��������� �������
            arr[item] = temp;
            item--;
        }
    }
}

template<class T>
T sort2(T* arr, int size)
{
    if (size < 2) return 0;

    int temp,// ��������� ���������� ��� �������� �������� �������� ������������ �������
        item;// ������ ����������� ��������
    for (int counter = 1; counter < size; counter++)
    {
        temp = arr[counter];// �������������� ��������� ���������� ������� ��������� �������� �������
        item = counter - 1;// ���������� ������ ����������� �������� �������
        while (item >= 0 && arr[item] < temp) // ���� ������ �� ����� 0 � ���������� ������� ������� ������ ��������
        {
            arr[item + 1] = arr[item];// ������������ ��������� �������
            arr[item] = temp;
            item--;
        }
    }
}