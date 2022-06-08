#include <iostream>
#include <vector>

using namespace std;

class Description
{
protected:

	const char* data;
	const char* type;

public:
	Description(const char* d, const char* t) : data(d), type(t) {};
	virtual ~Description() {};
	virtual void getDescription()
	{
		cout << type << data << endl;
	}
};


class Date_of_manufacture : public Description
{
public:
	Date_of_manufacture(const char* d) : Description(d, "Срок гоности: ") {};
	virtual ~Date_of_manufacture() {};
};

class Structure : public Description
{
public:
	Structure(const char* d) : Description(d, "Состав: ") {};
	virtual ~Structure() {};
};