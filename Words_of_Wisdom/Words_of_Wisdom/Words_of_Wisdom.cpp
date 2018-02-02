// Words_of_Wisdom.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Summator.h"
#include "Multiplier.h"
#include "ExpressionEvaluator.h"
#include "CustomExpressionEvaluator.h"
#include "IShuffle.h"

int _tmain(int argc, _TCHAR* argv[])
{
	ExpressionEvaluator* EEObjMassive[3]; //Массив эвалюаторов

	//Сумматор
	EEObjMassive[0] = new Summator(2);
	EEObjMassive[0]->setOperand(0, 39.1);
	EEObjMassive[0]->setOperand(1, -12.7);
	//----

	//Мультиплер
	EEObjMassive[1] = new Multiplier(4);
	double *tempparametrs = new double[4];
	tempparametrs[0] = -4.5;
	tempparametrs[1] = 2;
	tempparametrs[2] = 3;
	tempparametrs[3] = -10;
	EEObjMassive[1]->setOperand(tempparametrs, 4, true);
	delete []tempparametrs;
	tempparametrs = nullptr;
	//----
	
	//КастомЭкспрешнЭвалюатор
	EEObjMassive[2] = new CustomExpressionEvaluator(6);
	double *tempparametrs_2 = new double[6];
	tempparametrs_2[0] = 5;
	tempparametrs_2[1] = 16;
	tempparametrs_2[2] = -3;
	tempparametrs_2[3] = 10;
	tempparametrs_2[4] = 12;
	tempparametrs_2[5] = 14;
	EEObjMassive[2]->setOperand(tempparametrs_2, 6, true);
	delete []tempparametrs_2;
	tempparametrs_2 = nullptr;
	//----

	for(char i = 0; i < 3; i++) //Демонстрация работы расчёта
	{
		EEObjMassive[i]->logToScreen();
		EEObjMassive[i]->logToFile("evaluatorlog.log");
		std::cout << std::endl;
	}

	for(char i = 0; i < 3; i++) //Демонстрация RTTI
	{
		if((dynamic_cast<IShuffle*>(EEObjMassive[i])))
		{
			dynamic_cast<IShuffle*>(EEObjMassive[i])->shuffle();
			std::cout << std::endl;
			EEObjMassive[i]->logToScreen();
			EEObjMassive[i]->logToFile("ShuffleLog.log");
		}
	}

	for(char i = 0; i < 3; i++)
	{
		delete EEObjMassive[i];
		EEObjMassive[i] = nullptr;
	}
	//delete []EEObjMassive; //Degub Assertion Failed

	std::cout << std::endl;
	system("pause");

	return 0;
}

