#include "StdAfx.h"
#include "RStadium.h"
#include <iostream>
#include <string>
#include <fstream>


RStadium::RStadium(void)
{
}

RStadium::RStadium(std::string Address, std::string clubName, unsigned int sectorsCount, unsigned int Capacity, unsigned int Attendance) : Stadium(Address, clubName, sectorsCount, Capacity, Attendance)
{
}

void RStadium::serialize()
{
	std::cout << "Данная функция была переопределена в данном классе" << std::endl;
	std::cout << "в показательных целях, и больше не работает" << std::endl;
}

void RStadium::serialize(std::string filename)
{
	std::ofstream sFF(filename);
	sFF << "Данная функция была переопределена в данном классе" << std::endl;
	sFF << "в показательных целях, и больше не работает" << std::endl;
	sFF.close();
}


RStadium::~RStadium(void)
{
}
