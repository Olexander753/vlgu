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
			throw ("Файл не открыт");
		}
		
	}
	void writeData(int* data, int size) 
	{
		if (!data || size <= 0) 
		{
			throw ("Ошибка записи");
		}
		write((char*)data, size);
	}
	ofstream& operator<<(int data) 
	{
		writeData(&data, sizeof(data));
		return *this;
	}
};