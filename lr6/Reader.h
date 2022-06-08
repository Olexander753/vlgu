#ifndef READER_H
#define READER_H

#include <string>

class Reader {
public:
	std::string GetName();

	virtual ~Reader();

protected:

	// ���������� ����������� �� �������� ��������� ������� ������� ������, 
	// �� ����� �������������� � �������-��������
	Reader(const std::string& name);

private:
	std::string _name;

};


#endif // !READER_H
