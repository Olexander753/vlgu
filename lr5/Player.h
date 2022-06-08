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
		cout << "Имя " << name << endl
			<< "Дата рождения " << birthday << endl
			<< "Страна " << country << endl
			<< "Спортивный разряд " << sport_category << endl
			<< "Рейтинг " << rating << endl;
	}

	void getResults()
	{
		if (result.size() < 1)
			cout << "Нет результатов " << endl;
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