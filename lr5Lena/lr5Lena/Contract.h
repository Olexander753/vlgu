#pragma once
#include <iostream>
#include <vector>
#include "Worker.h"

using namespace std;

class Contract
{
	const char* chipher; //���� ��������
	const char* name_org; //��3����� ������3����
	const char* date; //����
	double sum; //����� ��������
	const char* view; // ���

	vector<Worker*> Workers; //������ ����������� � �������

public:
	Contract(const char* ch, const char* n, const char* d, double s, const char* v) :
		chipher(ch), name_org(n), date(d), sum(s), view(v) {}; //�����������

	virtual ~Contract() {}; //����������

	virtual void getContract() //�����, ������� ���� � ��������
	{
		cout << "���� �������� " << chipher << endl
			<< "�a������ ����������� " << name_org << endl
			<< "���� " << date << endl
			<< "����� �������� " << sum << endl
			<< "��� �������� " << view << endl << endl;
	}

	virtual void getWorkers() //������� ������ �����������
	{
		for (int i = 0; i < Workers.size(); i++)
		{
			Workers[i]->getWorker();
		}
	}

	virtual void addWorker(Worker* item) //�������� ���������� � ������
	{
		Workers.push_back(item);
	}
};


class Rent : public Contract
{
public:
	Rent(const char* ch, const char* n, const char* d, double s) :
		Contract(ch, n, d, s, "������ ") {};
	virtual ~Rent() {};
};

class Leasing : public Contract
{
public:
	Leasing(const char* ch, const char* n, const char* d, double s) :
		Contract(ch, n, d, s, "������ ") {};
	virtual ~Leasing() {};
};