#include <iostream> 
#include <vector> 
#include <fstream>
using namespace std;

class Train
{
	int numbertrain{ 0 };
	char station [20];
	int h{ 0 };
	int m{ 0 };
	int timeinroud{ 0 };
	int tikkets{ 0 };

public:
	Train() = default;
	Train(int Tnumbertrain, const char* Tstation, int Th, int Tm, int Ttimeinroud, int Ttikkets);
	~Train() = default;

	friend void write(vector<Train> t);
	friend void read(vector<Train>& t);
	friend istream& operator>> (istream& in, Train& item);
	friend ostream& operator<< (ostream& out, Train& item);
	friend void timetoroud(vector<Train> t, const char* cyti, int ah, int am, int bh, int bm);
	friend void havetikkets(vector<Train> t, int inumbertrain);

};