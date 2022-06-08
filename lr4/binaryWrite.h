#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class bin_outstream : public ofstream {
public:
	bin_outstream(const char* file) : ofstream(file, ios::app | ios::binary)
	{
		if (!file)
		{
			throw ("Error: Can't open file for writing");
		}
	}
	void writeData(int* data, int size)
	{
		if (!data || size <= 0)
		{
			throw ("Error: Write data error");
		}
		write((char*)data, size);
	}
	ofstream& operator<<(int data)
	{
		writeData(&data, sizeof(data));
		return *this;
	}
};