#pragma once
#include <iostream>

using namespace std;

class Result
{
public:
	Result(const char* idate, int iplace, const char* itournament) :
		data(idate), place(iplace), tournament(itournament) {};
	virtual ~Result() {};
	virtual void getResult()
	{
		cout << tournament << " " << data << endl << "Место " << place << endl;
	}

protected:
	const char* data;
	int place;
	const char* tournament;
};

class Russian_Championship : public Result
{
public:
	Russian_Championship(const char* idate, int iplace) : Result(idate, iplace, "Чемпионат России ") {};
};

class European_championship : public Result
{
public:
	European_championship(const char* idate, int iplace) : Result(idate, iplace, "Чемпионат Европы ") {};
};

class World_cup : public Result
{
public:
	World_cup(const char* idate, int iplace) : Result(idate, iplace, "Чемпионат Мира ") {};

};