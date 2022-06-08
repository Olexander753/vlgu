#pragma once
#include <iostream> 
#include <vector> 
#include <fstream>
#include "Exception.h"
using namespace std;

class Reader
{
	int id, num, year; // ���� �����. ��� �������, �������������� (����� ��������).
	char autor[20], name[20]; // �����. ��������

public:
	Reader() = default;
	Reader(int iid, const char* iautor, const char* iname, int iyear, int inum);
	~Reader() = default;
	friend void write(vector<Reader> item); //3��������� � ����
	friend void read(vector<Reader>& item); //������ �3 �����
	friend istream& operator>> (istream& in, Reader& item); //�������3�� ��������� �����
	friend ostream& operator<< (ostream& out, Reader& item); //�������3�� ��������� ������
	friend void place(vector<Reader> item, const char* iautor, const char* name);  //�������������� �����, ������ X �������� Y;
	friend void books_autor(vector<Reader> item, const char* iautor);              //������ ���� ������ Z, ����������� � ���������;
	friend void books_year(vector<Reader> item, int iyear);                        //����� ���� ������� XX ����, ��������� � ����������.

};

Reader::Reader(int iid, const char* iautor, const char* iname, int iyear, int inum)
{
	id = iid;
	strcpy_s(autor, iautor);
	strcpy_s(name, iname);
	year = iyear;
	num = inum;
}

istream& operator>>(istream& in, Reader& item)
{
	cout << "���������� � ������ ��������� ���������:" << endl;
	cout << "���� �����: ";
	in >> item.id;
	cout << "�����: ";
	in >> item.autor;
	cout << "��������: ";
	in >> item.name;
	cout << "��� �������:";
	in >> item.year;
	cout << "�������������� (����� ��������): ";
	in >> item.num;
	return in;
}

ostream& operator<<(ostream& out, Reader& item)
{
	out << endl << "���������� � ������ ��������� ���������: " << endl;
	out << "���� �����: " << item.id << endl;
	out << "�����: " << item.autor << endl;
	out << "��������: " << item.name << endl;
	out << "��� �������:" << item.year << endl;
	out << "�������������� (����� ��������): " << item.num << endl;
	return out;
}

void write(vector<Reader> item)
{
	ofstream fout;
	fout.open("Reader.dat", ofstream::app | ofstream::binary);

	for (int i = 0; i < item.size(); i++) {
		fout.write((char*)&item[i], sizeof(Reader));
	}

	fout.close();
}

void read(vector<Reader>& item)
{
	ifstream fin;
	fin.open("Reader.dat", ifstream::in | ifstream::binary);
	int i{ 0 };
	Reader temp;

	while (fin.read((char*)&temp, sizeof(Reader))) {
		item.push_back(temp);
		i++;
	}

	fin.close();
}

void place(vector<Reader> item, const char* iautor, const char* iname)
{
	int k = 0, m = 0, s = 0;
	char a[20], n[20];
	strcpy_s(a, iautor);
	strcpy_s(n, iname);
	for (int i = 0; i < item.size(); i++)
	{
		int j = 0;
		while (item[i].autor[j] != '\0')//���������� ������
		{
			k = 0;
			if (item[i].autor[j] == a[j])
			{
				k = 1;
			}
			j++;
		}
		int q = 0;
		while (item[i].name[q] != '\0')//���������� ���
		{
			m = 0;
			if (item[i].name[q] == n[q])
			{

				m = 1;
			}
			q++;
		}
		if (k == 1 && m == 1) //���� ��������� ��3����� � ����� �������
		{
			cout << "����� " << iname << " ������ " << iautor << " ��������� �� ������� �" << item[i].num << endl;
			s++;
		}

	}
	if (s == 0)
		throw Exception(HAVE_NOT_BOOK, "�a��� ����� ���");
}

void books_autor(vector<Reader> item, const char* iautor)
{
	int k = 0, s = 0;
	char a[20];
	strcpy_s(a, iautor);
	cout << "����� " << iautor << endl;
	for (int i = 0; i < item.size(); i++)
	{
		int j = 0;
		while (item[i].autor[j] != '\0')//���������� ������
		{
			k = 0;
			if (item[i].autor[j] == a[j])
			{
				k = 1;
			}
			j++;
		}
		if (k == 1) // ���� ����� ����� ���� ������� ��� �����
		{
			cout << "����� " << item[i].name << endl;
			s++;
		}
	}
	if (s == 0)
		throw Exception(HAVE_NOT_BOOK, "����� ������� ������ ���");
}
void books_year(vector<Reader> item, int iyear)
{
	int k = 0;
	for (int i = 0; i < item.size(); i++)
	{
		if (item[i].year == iyear)//���������� ���
			k++;
	}
	if (k == 0)
		throw Exception(HAVE_NOT_BOOK, "���� ������� ���� ���");
	else
		cout << "� ���������� ���� " << k << " ����� " << iyear << " ����" << endl; // ���� ����� ��� ������� ��� � ���-�� ����
}