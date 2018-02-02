// Memories from a Distant Past.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Stadium.h"
#include <clocale>
#include <iostream>
#include <iomanip>
#include <string>
#include "PStadium.h"
#include "FStadium.h"
#include "RStadium.h"

void screenOutput(char* str)
{
	std::cout << std::endl << str << std::endl << std::endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	
	screenOutput("������������ ������ '�������'");

	//�������� ���������
	Stadium* stadiums[3];
	stadiums[0] = new Stadium();
	stadiums[1] = new PStadium();
	stadiums[2] = new RStadium("��. �������������, 128, 256", "������", 10, 20000, 1000);
	//�������� ���������

	//�������
	stadiums[0]->setAddress("��. �����������, 15");
	stadiums[0]->setClubName("�������");
	stadiums[0]->setSectorCount(100);
	stadiums[0]->setCapacity(100000);
	stadiums[0]->setAttendance(599999);
	//---
	stadiums[1]->setAddress("��. ������ ����������, -1, -1");
	stadiums[1]->setClubName("BeerBand");
	stadiums[1]->setSectorCount(12);
	stadiums[1]->setCapacity(1000);
	stadiums[1]->setAttendance(300);
	//�������

	screenOutput("\n\n ������� ������ � ��������:");

	std::cout << "������: " << stadiums[0]->getAddress() << std::endl << "����: " << stadiums[0]->getClubName() << std::endl << "���������� ��������: " << stadiums[0]->getSectorCount() << std::endl << "�����������: " << stadiums[0]->getCapacity() << std::endl << "������������: " << stadiums[0]->getAttendance() <<std::endl << std::endl;
	std::cout << "������: " << stadiums[1]->getAddress() << std::endl << "����: " << stadiums[1]->getClubName() << std::endl << "���������� ��������: " << stadiums[1]->getSectorCount() << std::endl << "�����������: " << stadiums[1]->getCapacity() << std::endl << "������������: " << stadiums[1]->getAttendance() <<std::endl << std::endl;
	std::cout << "������: " << stadiums[2]->getAddress() << std::endl << "����: " << stadiums[2]->getClubName() << std::endl << "���������� ��������: " << stadiums[2]->getSectorCount() << std::endl << "�����������: " << stadiums[2]->getCapacity() << std::endl << "������������: " << stadiums[2]->getAttendance() <<std::endl << std::endl;
	stadiums[2]->serialize();
	stadiums[2]->serialize("serlog.log");
	std::cout << std::endl;

	for(char i = 0; i < 3; i++)
	{
		if((dynamic_cast<IPercentCalculate*>(stadiums[i])))
		{
			std::cout << "������� ���������� �������� PStadium = " << dynamic_cast<IPercentCalculate*>(stadiums[i])->calcPercent() << '%' <<  std::endl;
		}
	}
	

	system("pause");
	
	return 0;
}

