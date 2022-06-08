#include "UniversityLibraryStrategy.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

UniversityLibraryStrategy::UniversityLibraryStrategy(int averagePeriod) : _averagePeriod(averagePeriod) {}

UniversityLibraryStrategy::~UniversityLibraryStrategy() {}

int UniversityLibraryStrategy::HoldPeriod(const Reader& reader) const {
	// ��� ���� ���������� ��������� ��������� ����� ������ ������� ��������
	int result = _averagePeriod;

	//
	// ����������, ������ ������ ����������� ��������: ������� ��� 
	// �������������.
	//

	const Student* student = dynamic_cast<const Student*>(&reader);
	const Lecturer* lecturer = dynamic_cast<const Lecturer*>(&reader);
	const Engineer* lab_assistant = dynamic_cast<const Engineer*>(&reader);


	if (student != NULL) {
		if (student->GetClass() < 3) {
			// ������� ����
			result = _averagePeriod / 2;
		}
		else {
			// ������� ����
			result = _averagePeriod;
		}
	}
	else if (lecturer != NULL) {
		if (_averagePeriod != NULL) {
			// ��� �������������
			result = _averagePeriod * 2;
		}
	}
	else if (lab_assistant != NULL) {
		if (_averagePeriod != NULL) {
			// ��� ���������
			result = _averagePeriod * 2;
		}
	}

	return result;
}
