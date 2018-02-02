#include "StdAfx.h"
#include "PStadium.h"


PStadium::PStadium(void)
{
}

PStadium::PStadium(std::string Address, std::string clubName, unsigned int sectorsCount, unsigned int Capacity, unsigned int Attendance) : Stadium(Address, clubName, sectorsCount, Capacity, Attendance)
{
}

double PStadium::calcPercent(void)
{
	if (this->capacity == 0) {return -1;}
	return (this->attendance * 100) / this->capacity;
}

PStadium::~PStadium(void)
{
}
