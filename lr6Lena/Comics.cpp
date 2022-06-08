#include "Comics.h"

Comics::Comics(const std::string& ititle, double iprice, const std::string& iyear)
	: title(ititle), price(iprice), year(iyear) {}

Comics::~Comics() {}
