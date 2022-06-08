#ifndef PurchaseNameStrategy_H
#define PurchaseNameStrategy_H

#include "IPurchaseStrategy.h"

class PurchaseNameStrategy : public IPurchaseStrategy {
public:
	bool IsAcceptable(const IItem& item);
	PurchaseNameStrategy(const char* isname);
	virtual ~PurchaseNameStrategy();

private:
	const char* sname;
};


PurchaseNameStrategy::PurchaseNameStrategy(const char* isname) : sname(isname) {}

PurchaseNameStrategy::~PurchaseNameStrategy() {}

bool PurchaseNameStrategy::IsAcceptable(const IItem& item) {
	bool result = true;
	//���� ��3����� ����� �������� � ��3������ �������� �3����
	//���3����� � 3����� �� �������� ��� �������� �3�����
	if (sname != item.GetTitle()) { 
		result = false;
	}

	return result;
}
#endif // !PurchaseNameStrategy_H


//���������� ���������� ��������� ������� �������� �������;