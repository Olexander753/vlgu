#pragma once


#include <iostream>

using namespace std;

class Country
{
	const char *name, //на3вание
		*fog; //форма правления
	float area; //площадь

public:
	Country() : name("NULL"), fog("NULL"), area(0.0) {};
	Country(const char* iname, const char* ifog, float iarea): name(iname), fog(ifog), area(iarea) {};
	~Country() = default;
	void Print();
	void Input(const char* iname, const char* ifog, float iarea);
	
	//перегру3ка опрератора вывода
	friend ostream& operator<< (ostream& out, const Country& item) {
		cout << "Информация о " << item.name << ": " << endl;
		cout << "Форма правления: " << item.fog << endl;
		cout << "Площадь: " << item.area << endl << endl;

		return out;
	}
	//перегру3ка опрератора ==
	bool operator==(Country& item)
	{
		if (name == item.name && fog == item.fog && area == item.area)
			return true;
		else
			return false;
	}
};

void Country::Print()
{
	cout << "Информация о " << name << ": " << endl;
	cout << "Форма правления: " << fog << endl;
	cout << "Площадь: " << area << endl << endl;
}

void Country::Input(const char* iname, const char* ifog, float iarea)
{
	name = iname;
	fog = ifog;
	area = iarea;
}