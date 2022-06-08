#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Worker
{
	const char* name; //���
	const char* addres; //�����
	const char* telefon; //�������
	const char* post; //���������
	double salary; //�����
	const char* date; //����� ������ ������� ���������� �� ������� ��������


public:
	Worker(const char* n, const char* a, const char* t, const char* p, double s, const char* d) :
		name(n), addres(a), telefon(t), post(p), salary(s), date(d) {}; //�����������
	virtual ~Worker() {}; //����������
	virtual void getWorker() //������� ���� � ����������
	{
		cout << "��� ���������� " << name << endl
			<< "����� ����������" << addres << endl
			<< "������� ���������� " << telefon << endl
			<< "��������� ���������� " << post << endl
			<< "����� ��������� " << salary << endl
			<< "����� ������ �� �������� " << date << endl << endl;
	}
};

class Engineer : public Worker //����������� ����� ������� �� ������ ���������, ������ � ��������� ������������� �������
{
public:
	Engineer(const char* n, const char* a, const char* t, double s, const char* d) :
		Worker(n, a, t, "�������", s, d) {}; //����������� 
	virtual ~Engineer() {}; //����������
};

class Programmer : public Worker //����������� ����� ����������� �� ������ ���������, ������ � ��������� ������������� �����������
{
public:
	Programmer(const char* n, const char* a, const char* t, double s, const char* d) :
		Worker(n, a, t, "�����������", s, d) {}; //�����������
	virtual ~Programmer() {}; //����������
};