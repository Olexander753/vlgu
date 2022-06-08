#ifndef IPURCHASESTRATEGY_H
#define IPURCHASESTRATEGY_H

#include "IItem.h"

class IPurchaseStrategy {
public:

	// ���������� true, ���� �������� ������� �������� ��� �������.
	// ����� ���������� ������ �� ������ (�������� �������
	// ������������ ������ �� �������� �� ����� ���� ���������, �.�.
	// ������� ��������������� �������)
	virtual bool IsAcceptable(const IItem& item) = 0;

};


#endif // !IPURCHASESTRATEGY_H

