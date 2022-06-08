#ifndef PUBLICLIBRARYSTRATEGY_H
#define PUBLICLIBRARYSTRATEGY_H

#include "IDeliveryStrategy.h"

//
// ���������� ��������� ����������� ������� �������� ������.
// � ������ ������ (��������� ����������) ������ ��� 
// ���� ��������� ��������� ����������. �� �������� ���
// �������� ���������� ���������
//
class PublicLibraryStrategy : public IDeliveryStrategy
{
public:
	PublicLibraryStrategy(int nomianlHoldPeriod);
	virtual ~PublicLibraryStrategy();

	// ���������� ������ ���������� ���������
	int HoldPeriod(const Reader& reader) const;

private:
	int _nomianlHoldPeriod;

};


#endif // !PUBLICLIBRARYSTRATEGY_H
