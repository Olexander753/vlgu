#include <iostream>
#include <vector>
#include "Tovar.h"
#include "Postavchik.h"

class Baze
{
	std::vector<Tovar> TovarNaBaze;
	std::vector<Postavchik> PostavchikBaze;

public:
	Baze() {};
	virtual ~Baze() {};

	void outTovar()
	{
		for (int i = 0; i < TovarNaBaze.size(); i++)
		{
			TovarNaBaze[i].outT();
			TovarNaBaze[i].getDescription();
			cout << endl;
		}
	}

	void outPostavchik()
	{
		for (int i = 0; i < TovarNaBaze.size(); i++)
		{
			PostavchikBaze[i].outP();
			cout << endl;
		}
	}

	void addTovar(Tovar& item)
	{
		TovarNaBaze.push_back(item);
	}

	void addPostavchik(Postavchik& item)
	{
		PostavchikBaze.push_back(item);
	}
};