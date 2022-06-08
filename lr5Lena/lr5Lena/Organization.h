#pragma once
#include <iostream>
#include <vector>
#include "Contract.h"

using namespace std;

class Organization
{
	vector<Contract*> Contracts; //������ ����������

public:
	Organization() {}; //�����������
	virtual ~Organization() {};//����������

	void getContracts()//�����, ������� ������ ����������, � ������ ���������� �� ����������� ���������
	{
		for (int i = 0; i < Contracts.size(); i++)
		{
			Contracts[i]->getContract();
			cout << "����������: " << endl;
			Contracts[i]->getWorkers();
			cout << endl;
		}
	}

	void addContract(Contract* item) //�����, ��������� � ������ ���������� ����� ��������.
	{
		Contracts.push_back(item);
	}

};