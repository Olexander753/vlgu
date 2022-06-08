#pragma once
#include <iostream>
#include <vector>
#include "Result.h"

using namespace std;

class Player
{
	const char* name;
	int birthday;
	const char* country;
	const char* sport_category;
	int rating;
	vector<Result*> result;

public:
	Player(const char* iname, int ibirthday, const char* icountry, const char* isport_category, int irating) :
		name(iname), birthday(ibirthday), country(icountry), sport_category(isport_category), rating(irating) {};
	
	void getName()
	{
		cout << "��� " << name << endl
			<< "���� �������� " << birthday << endl
			<< "������ " << country << endl
			<< "���������� ������ " << sport_category << endl
			<< "������� " << rating << endl;
	}

	void getResults()
	{
		if (result.size() < 1)
			cout << "��� ����������� " << endl;
		for (int i = 0; i < result.size(); i++)
		{
			result[i]->getResult();
		}
	}

	void addResults(Result* res) 
	{
		result.push_back(res);
	}
};