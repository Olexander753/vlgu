#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Worker
{
	const char* name; //ФИО
	const char* addres; //адрес
	const char* telefon; //телефон
	const char* post; //должность
	double salary; //оклад
	const char* date; //сроки работы данного сотрудника по данному договору


public:
	Worker(const char* n, const char* a, const char* t, const char* p, double s, const char* d) :
		name(n), addres(a), telefon(t), post(p), salary(s), date(d) {}; //конструктор
	virtual ~Worker() {}; //деструктор
	virtual void getWorker() //выводит инфо о сотруднике
	{
		cout << "Имя сотрудника " << name << endl
			<< "адрес сотрудника" << addres << endl
			<< "телефон сотрудника " << telefon << endl
			<< "должность сотрудника " << post << endl
			<< "оклад сотудника " << salary << endl
			<< "сроки работы по договору " << date << endl << endl;
	}
};

class Engineer : public Worker //наследуемый класс инженер от класса сотрудник, просто в должности прописывается инженер
{
public:
	Engineer(const char* n, const char* a, const char* t, double s, const char* d) :
		Worker(n, a, t, "Инженер", s, d) {}; //конструктор 
	virtual ~Engineer() {}; //деструктор
};

class Programmer : public Worker //наследуемый класс программист от класса сотрудник, просто в должности прописывается программист
{
public:
	Programmer(const char* n, const char* a, const char* t, double s, const char* d) :
		Worker(n, a, t, "Программист", s, d) {}; //конструктор
	virtual ~Programmer() {}; //деструктор
};