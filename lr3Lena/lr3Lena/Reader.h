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
	friend void place(vector<Reader> item, const char *iautor, const char *name);  //�������������� �����, ������ X �������� Y;
	friend void books_autor(vector<Reader> item, const char* iautor);              //������ ���� ������ Z, ����������� � ���������;
	friend void books_year(vector<Reader> item, int iyear);                        //����� ���� ������� XX ����, ��������� � ����������.

};

Reader::Reader(int iid,  const char* iautor, const char* iname, int iyear, int inum)
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
	ofstream out("Reader1.txt", ios::out);//��������� ���� 
	if (!out)
	{
		throw Exception(FILE_CANNOT_OPEN, "������ ���� �� ������");
	}
	for (int i = 0; i < item.size(); i++) //3�������� ����3 ����
	{
		out << item[i].id << " " << item[i].name << " " << item[i].autor << " " << item[i].year << " " << item[i].num << endl;
	}
	out.close();
}

void read(vector<Reader>& item)
{
	ifstream in("Reader2.txt", ios::in);//��������� ���� 
	if (!in)
	{
		throw Exception(FILE_CANNOT_OPEN, "������ ���� �� ������");
	}
	if (in.eof())
	{
		throw Exception(FILE_IS_EMPTY, "���� ������");
	}
	while (!in.eof())//���� �� ����� ����� ������ �3 ����
	{
		char sym;
		char info[20];
		int i = 0;
		int c = 0;
		Reader r;

		in.get(sym);
		while (sym != ' ')
		{
			info[i] = sym;
			i++;
			in.get(sym);
		}
		for (int j = 0; j < i; j++)
		{
			c = c * 10;
			c = info[j] - '0' + c;
		}
		r.id = c; //������� ���� �����

		in.get(sym);
		i = 0;
		while (sym != ' ')
		{
			info[i] = sym;
			i++;
			in.get(sym);
		}
		info[i++] = '\0';
		strcpy_s(r.autor, info);//������� ������

		in.get(sym);
		i = 0;
		while (sym != ' ')
		{
			info[i] = sym;
			i++;
			in.get(sym);
		}
		info[i++] = '\0';
		strcpy_s(r.name, info);//������� ��3�����

		in.get(sym);
		i = 0;
		c = 0;
		while (sym != ' ')
		{
			info[i] = sym;
			i++;
			in.get(sym);
		}
		for (int j = 0; j < i; j++)
		{
			c = c * 10;
			c = info[j] - '0' + c;
		}
		r.year = c;//������� ���

		in.get(sym);
		i = 0;
		c = 0;
		while (sym != ' ' && sym != '\n' && !in.eof())
		{
			info[i] = sym;
			i++;
			in.get(sym);
		}
		for (int j = 0; j < i; j++)
		{
			c = c * 10;
			c = info[j] - '0' + c;
		}
		r.num = c;//������� ����� �������
		item.push_back(r);//3��������� � ������
	}
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
		cout << "� ���������� ���� " << k << " ����� " << iyear << " ����"<< endl; // ���� ����� ��� ������� ��� � ���-�� ����
}