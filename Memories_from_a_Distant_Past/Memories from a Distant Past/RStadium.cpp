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
	std::cout << "������ ������� ���� �������������� � ������ ������" << std::endl;
	std::cout << "� ������������� �����, � ������ �� ��������" << std::endl;
}

void RStadium::serialize(std::string filename)
{
	std::ofstream sFF(filename);
	sFF << "������ ������� ���� �������������� � ������ ������" << std::endl;
	sFF << "� ������������� �����, � ������ �� ��������" << std::endl;
	sFF.close();
}


RStadium::~RStadium(void)
{
}
