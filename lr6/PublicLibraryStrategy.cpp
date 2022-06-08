#include "PublicLibraryStrategy.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PublicLibraryStrategy::PublicLibraryStrategy(int nomianlHoldPeriod)
	: _nomianlHoldPeriod(nomianlHoldPeriod)
{}

PublicLibraryStrategy::~PublicLibraryStrategy() {}

int PublicLibraryStrategy::HoldPeriod(const Reader& reader) const {
	// �� �������� �� ��������� ��������, ������ ��� ���� ����������
	return _nomianlHoldPeriod;
}
