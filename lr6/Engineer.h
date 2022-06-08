#ifndef GRADUATEST_H
#define GRADUATEST_H

#include "Reader.h"

class Engineer : public Reader {
public:
	Engineer(const std::string iname, const int icabinet);
	virtual ~Engineer();

	int GetCabinet() const { return cabinet; }

private:
	int cabinet;
};

#endif // !GRADUATEST_H
