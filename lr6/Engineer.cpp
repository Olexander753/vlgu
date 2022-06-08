#include "Engineer.h"

Engineer::Engineer(const std::string iname, int icabinet)
	: Reader(iname), cabinet(icabinet) {}

Engineer::~Engineer() {}
