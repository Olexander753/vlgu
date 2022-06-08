#ifndef Programmer_H
#define Programmer_H

#include "Reader.h"

class Programmer : public Reader {
public:
	Programmer(const std::string iname, const int iexperience);
	virtual ~Programmer();

	int GetExperience() const { return experience; }

private:
	int experience;//����� ������
};

#endif // !Programmer_H

//�������� ���� ����� ��������� ��������� (��������, ������� � �.�.);
//� ��� �����������
