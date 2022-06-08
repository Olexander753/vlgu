#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class bin_instream : public ifstream {
public:
	bin_instream(const char* file) : ifstream(file, ios::in | ios::binary) 
	{
		if (!file) 
		{
			throw ("���� �� �����������");
		}
	}
	void readData(int* data, int size) 
	{
		if (!data || size <= 0) 
		{
			throw ("������ ������");
		}
		read((char*)data, size);
	}
	bin_instream& operator>>(int& data)
	{
		readData(&data, sizeof(data));
		return *this;
	}
};
