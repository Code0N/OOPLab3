#include "StdAfx.h"
#include "CustomExpressionEvaluator.h"
#include <fstream>
//#include <string>


CustomExpressionEvaluator::CustomExpressionEvaluator(void)
{
}

CustomExpressionEvaluator::CustomExpressionEvaluator(unsigned int N)
{

}

double CustomExpressionEvaluator::Calculate()
{
	double tempresult = this->OperandsArray[0] - (this->OperandsArray[1] / 2);
	for(unsigned int i = 2; i < this->OperandsCount; i++)
	{
		if ((i+1) % 2 == 0)
		{
			tempresult -= this->OperandsArray[i] / (i+1);
		}
		else
		{
			tempresult += this->OperandsArray[i] / (i+1);
		}
	}
	return tempresult;
}

void CustomExpressionEvaluator::shuffle()
{
	double minarrel;
	for(unsigned int i = 0; i < this->OperandsCount; i++)
	{
		for(unsigned int j = i + 1; j < this->OperandsCount; j++)
		{
			if((this->OperandsArray[i] < this->OperandsArray[j]) && (this->OperandsArray[j] > 0) && (this->OperandsArray[i] > 0))
			{
				minarrel = this->OperandsArray[j];
				this->OperandsArray[j] = this->OperandsArray[i];
				this->OperandsArray[i] = minarrel;
			}
		}
	}
}

void CustomExpressionEvaluator::shuffle(unsigned int i, unsigned int j)
{
	double minarrel;
	for(unsigned int _i = i, _j = i; _i < j; _i++)
	{
		minarrel = this->OperandsArray[_i];
		_j = _i-1;
		while((_j > 0) && (this->OperandsArray[_i] > minarrel))
		{
			this->OperandsArray[_j + 1] = this->OperandsArray[_j];
			_j--;
		}
		this->OperandsArray[_j + 1] = minarrel;
	}
}

CustomExpressionEvaluator::~CustomExpressionEvaluator(void)
{
}

void CustomExpressionEvaluator::logToScreen()
{
	char _sign = '-';
	for (unsigned int i = 0; i < this->OperandsCount-1; i++)
	{
		std::cout << "Op" << i+1 << ", ";
	}
	std::cout << "Op" << this->OperandsCount << " : ";
	std::cout << this->formatNumber(this->OperandsArray[0]) << " " << _sign << " ";
	for (unsigned int i = 1; i < this->OperandsCount-1; i++)
	{
		if ((i % 2 == 0)) {_sign = '-';} else {_sign = '+';}
		std::cout << this->formatNumber(this->OperandsArray[i]) << '/' << i+1 << " " << _sign << " ";
	}
	std::cout << this->formatNumber(this->OperandsArray[this->OperandsCount-1]) << '/' << this->OperandsCount;
	std::cout << std::endl << "-> " << " " << this->formatNumber(this->Calculate());
}

void CustomExpressionEvaluator::logToFile(std::string filename)
{
	std::ofstream logFile(filename, std::ios_base::app | std::ios_base::out);
	for (unsigned int i = 0; i < this->OperandsCount; i++)
	{
		logFile << "Op" << i+1 << ", ";
	}
	logFile << "Op" << this->OperandsCount-1 << " : ";
	char _sign = '-';
	logFile << this->formatNumber(this->OperandsArray[0]) << " " << _sign << " ";
	for (unsigned int i = 1; i < this->OperandsCount-1; i++)
	{
		if ((i % 2 == 0)) {_sign = '-';} else {_sign = '+';}
		logFile << this->formatNumber(this->OperandsArray[i]) << '/' << i << " " << _sign << " ";
	}
	logFile << this->formatNumber(this->OperandsArray[this->OperandsCount-1]);
	logFile << std::endl << "-> " << " " << this->formatNumber(this->Calculate()) << std::endl;
}