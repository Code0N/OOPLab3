#include "StdAfx.h"
#include "FStadium.h"


FStadium::FStadium(void)
{
}

FStadium::FStadium(std::string Address, std::string clubName, unsigned int sectorsCount, unsigned int Capacity, unsigned int Attendance) : PStadium(Address, clubName, sectorsCount, Capacity, Attendance)
{
}

FStadium::~FStadium(void)
{
}
