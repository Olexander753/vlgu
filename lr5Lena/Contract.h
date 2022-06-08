#pragma once
#include <iostream>
#include <vector>
#include "Worker.h"

using namespace std;

class Contract
{
	const char* chipher; //шифр договора
	const char* name_org; //на3вание ограни3ации
	const char* date; //дата
	double sum; //сумма договора
	const char* view; // вид

	vector<Worker*> Workers; //список сотрудников в договре

public:
	Contract(const char* ch, const char* n, const char* d, double s, const char* v) :
		chipher(ch), name_org(n), date(d), sum(s), view(v) {}; //конструктор

	virtual ~Contract() {}; //деструктор

	virtual void getContract() //метод, выводит инфо о контраке
	{
		cout << "Шифр договора " << chipher << endl
			<< "нaзвание огранизации " << name_org << endl
			<< "дата " << date << endl
			<< "сумаа договора " << sum << endl
			<< "вид договора " << view << endl << endl;
	}

	virtual void getWorkers() //выводит список сотрудников
	{
		for (int i = 0; i < Workers.size(); i++)
		{
			Workers[i]->getWorker();
		}
	}

	virtual void addWorker(Worker* item) //добаляет сотрудника в список
	{
		Workers.push_back(item);
	}
};


class Rent : public Contract
{
public:
	Rent(const char* ch, const char* n, const char* d, double s) :
		Contract(ch, n, d, s, "Аренда ") {};
	virtual ~Rent() {};
};

class Leasing : public Contract
{
public:
	Leasing(const char* ch, const char* n, const char* d, double s) :
		Contract(ch, n, d, s, "Лизинг ") {};
	virtual ~Leasing() {};
};