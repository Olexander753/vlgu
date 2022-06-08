#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Sort.h"
#include "Exception.h"
using namespace std;

class f
{
	char ch;

public:
	explicit f(const char* path);
	~f() = default;
};

f::f(const char* path)
{
	ifstream in(path, ios::in);
	if (!in.is_open())
		throw Exception(FILE_CANNOT_OPEN, "Error: Can't open file");
	int arr1[50];
	int arr2[50];
	ch = -1;
	int item[8];
	int i = 0, j = 0;
	while (!in.eof()) //���� ���� �� ����� �����
	{
		int temp = 0;
		while (ch == -1 || ch == ' ' || ch == '\r' || ch == '\n' || ch == '\t')
		{
			in.get(ch);
			if (in.eof()) return;
		}
		while (ch != ' ')//�������� ����� ���� �� ������
		{
			temp = temp * 10;
			temp = temp + ch - '0';
			in.get(ch);
		}
		if (temp % 2 == 0)//�������� �� �������� � 3����� � ������ 
		{
			arr1[i] = temp;
			i++;
		}
		else
		{
			arr2[j] = temp;
			j++;
		}
		in.get(ch);
	}
	in.close(); //3������� ����

	sort1(arr1, i); //���������, ����������� ������� �3 ������� ���� ��� �� �� 3����������� ��� ���, ��� � ��������� �����
	sort2(arr2, j); //�� � ������� ���������������� ��� �� ������������� �� ��������


	ofstream out("x.txt", ios::out); // ��������� ������ ���� � 3�������� ������ ������ �����
	if (out.is_open())
	{
		for (int q = 0; q < i; q++)
		{
			out << arr1[q] << " ";
		}
	}
	else
	{
		throw Exception(FILE_CANNOT_OPEN, "������ ���� �� ������");
	}
	out.close();

	ofstream out1("y.txt", ios::out);// ��������� ������ ���� � 3�������� ������ �������� �����
	if (out1.is_open())
	{
		for (int q = 0; q < j; q++)
		{
			out1 << arr2[q] << " ";
		}
	}
	else
	{
		throw Exception(FILE_CANNOT_OPEN, "������ ���� �� ������");
	}
	out1.close();
}