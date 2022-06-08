#ifndef LAB_ASSISTANT_H
#define LAB_ASSISTANT_H

#include "Reader.h"

class Lab_assistant : public Reader {
public:
	Lab_assistant(const std::string iname, const int icabinet);
	virtual ~Lab_assistant();

	int GetCabinet() const { return cabinet; }

private:
	int cabinet;
};

#endif // !LAB_ASSISTANT_H
