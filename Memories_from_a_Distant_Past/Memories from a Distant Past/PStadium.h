#pragma once

#include "stadium.h"
#include "IPercentCalculate.h"

class PStadium :
	public Stadium, public IPercentCalculate
{
public:
	PStadium(void);
	PStadium(std::string Address, std::string clubName, unsigned int sectorsCount, unsigned int Capacity, unsigned int Attendance);
	double calcPercent(void);
	~PStadium(void);
};

