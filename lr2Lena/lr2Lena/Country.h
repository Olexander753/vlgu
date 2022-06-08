#pragma once


#include <iostream>

using namespace std;

class Country
{
	const char *name, //��3�����
		*fog; //����� ���������
	float area; //�������

public:
	Country() : name("NULL"), fog("NULL"), area(0.0) {};
	Country(const char* iname, const char* ifog, float iarea): name(iname), fog(ifog), area(iarea) {};
	~Country() = default;
	void Print();
	void Input(const char* iname, const char* ifog, float iarea);
	
	//�������3�� ���������� ������
	friend ostream& operator<< (ostream& out, const Country& item) {
		cout << "���������� � " << item.name << ": " << endl;
		cout << "����� ���������: " << item.fog << endl;
		cout << "�������: " << item.area << endl << endl;

		return out;
	}
	//�������3�� ���������� ==
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
	cout << "���������� � " << name << ": " << endl;
	cout << "����� ���������: " << fog << endl;
	cout << "�������: " << area << endl << endl;
}

void Country::Input(const char* iname, const char* ifog, float iarea)
{
	name = iname;
	fog = ifog;
	area = iarea;
}