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
		cout << "��� ����������: " << name << endl
			<< "����� ����������:  " << number << endl
			<< "���� ��������: " << deliverytime << endl
			<< "���������� ������ ��������:  " << deliveryquantity << endl;
	}
};