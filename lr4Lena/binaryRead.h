#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Exception.h"

using namespace std;

class bin_instream : public ifstream {
public:
	bin_instream(const char* file) : ifstream(file, ios::in | ios::binary)
	{
		if (!file)
		{
			throw Exception(FILE_CANNOT_OPEN, "Ошибка файл не открыт");
		}
	}
	void readData(int* data, int size)
	{
		if (!data || size <= 0)
		{
			throw Exception(FILE_CANNOT_READ, "Ошибка чтения");
		}
		read((char*)data, size);
	}
	bin_instream& operator>>(int& data)
	{
		readData(&data, sizeof(data));
		return *this;
	}
};
