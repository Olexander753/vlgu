#include <iostream>
#include <vector>
#include "Description.h"

using namespace std;

class Tovar
{
	const char* name;
	int id;
	int quantity;
	int price;

	vector<Description*> DescriptionTovar;

public:
	Tovar(const char* tname, int tid, int tquantity, int tprice) :
		name(tname), id(tid), quantity(tquantity), price(tprice) {};

	void outT()
	{
		cout << "�������� ������: " << name << endl
			<< "ID ������: " << id << endl
			<< "���������� ������ �� ����: " << quantity << endl
			<< "����: " << price << "������" << endl;
	}

	void getDescription()
	{
		for (int i = 0; i < DescriptionTovar.size(); i++)
		{
			DescriptionTovar[i]->getDescription();
		}
	}

	void addNewDescription(Description* des)
	{
		DescriptionTovar.push_back(des);
	}
};