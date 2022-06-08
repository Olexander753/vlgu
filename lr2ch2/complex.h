#include <iostream>

using namespace std;

class complex
{
	int re;
	int im;

public:

	complex();
	complex(int cre, int cim);
	~complex() = default;
	void print();
	void input(int cre, int cim);

	friend ostream& operator<< (ostream& out, const complex& item)
	{
		cout << item.im << "+" << item.re << "i" ;

		return out;
	}

	complex operator-(complex& item)
	{
		int c1re = re;
		int c1im = im;
		int c2re = item.re;
		int c2im = item.im;

		c1re = c1re - c2re;
		c1im = c1im - c2im;
		return complex(c1re, c1im);

	}
};


complex::complex()
{
	re = 0;
	im = 0;
}

complex::complex(int cre, int cim)
{
	re = cre;
	im = cim;
}

void complex::print()
{
	cout << re << im << endl;
}

void complex::input(int cre, int cim)
{
	re = cre;
	im = cim;
}