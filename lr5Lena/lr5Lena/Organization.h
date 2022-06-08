#pragma once
#include <iostream>
#include <vector>
#include "Contract.h"

using namespace std;

class Organization
{
	vector<Contract*> Contracts; //список контрактов

public:
	Organization() {}; //конструктор
	virtual ~Organization() {};//деструктор

	void getContracts()//метод, выводит список контрактов, и список работников по опрделённому контаркту
	{
		for (int i = 0; i < Contracts.size(); i++)
		{
			Contracts[i]->getContract();
			cout << "Сотрудники: " << endl;
			Contracts[i]->getWorkers();
			cout << endl;
		}
	}

	void addContract(Contract* item) //метод, добавляет в список контрактов новый контракт.
	{
		Contracts.push_back(item);
	}

};