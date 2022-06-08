#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Exception.h"

using namespace std;

class bin_outstream : public ofstream {
public:
	bin_outstream(const char* file) : ofstream(file, ios::app | ios::binary)
	{
		if (!file)
		{
			throw Exception(FILE_CANNOT_OPEN, "������ ���� �� ������");
		}

	}
	void writeData(int* data, int size)
	{
		if (!data || size <= 0)
		{
			throw Exception(FILE_CANNOT_WRITE, "������ ������");
		}
		write((char*)data, size);
	}
	ofstream& operator<<(int data)
	{
		writeData(&data, sizeof(data));
		return *this;
	}
};