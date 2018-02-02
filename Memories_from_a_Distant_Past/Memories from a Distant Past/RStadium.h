#pragma once
#include "stadium.h"
class RStadium :
	public Stadium
{
public:
	RStadium(void);
	RStadium(std::string Address, std::string clubName, unsigned int sectorsCount, unsigned int Capacity, unsigned int Attendance);
	void serialize();
	void serialize(std::string filename);
	~RStadium(void);
};

