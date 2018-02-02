#pragma once

#include "pstadium.h"
#include "RStadium.h"

class FStadium :
	public PStadium, RStadium
{
public:
	FStadium(void);
	FStadium(std::string Address, std::string clubName, unsigned int sectorsCount, unsigned int Capacity, unsigned int Attendance);
	~FStadium(void);
};

