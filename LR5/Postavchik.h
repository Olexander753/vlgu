#include <iostream>
#include <vector>

using namespace std;

class Postavchik
{
	const char* name;
	int number;
	const char* deliverytime;
	int deliveryquantity;

public:
	Postavchik(const char* iname, int inumber, const char* ideliverytime, int ideliveryquantity) :
		name(iname), number(inumber), deliverytime(ideliverytime), deliveryquantity(ideliveryquantity) {};
	
	void outP()
	{
		cout << "Имя поставшика: " << name << endl
			<< "Номер поставщика:  " << number << endl
			<< "Дата поставки: " << deliverytime << endl
			<< "Количество товара поставки:  " << deliveryquantity << endl;
	}
};