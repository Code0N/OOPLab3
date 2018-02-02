#include "StdAfx.h"
#include "ExpressionEvaluator.h"
#include "ILoggable.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


ExpressionEvaluator::ExpressionEvaluator(void)
{
	this->OperandsCount = 20;
	this->OperandsArray = new double[this->OperandsCount];
	for(unsigned int i = 0; i < 19; i++)
	{
		this->OperandsArray[i] = 0;
	}
	this->sign = 'U'; //будет перекрыто в наследниках
}

ExpressionEvaluator::ExpressionEvaluator(unsigned int N)
{
	this->OperandsCount = N;
	this->OperandsArray = new double[this->OperandsCount];
	for(unsigned int i = 0; i < N; i++)
	{
		this->OperandsArray[i] = 0;
	}
	this->sign = 'U'; //будет перекрыто в наследниках
}

void ExpressionEvaluator::setOperand(unsigned int pos, double value)
{
	if (pos > this->OperandsCount) {return;}
	this->OperandsArray[pos] = value;
}

void ExpressionEvaluator::setOperand(double ops[], unsigned int Count, bool erase)
{
	if (erase)
	{
		delete []this->OperandsArray;
		this->OperandsCount = Count;
		this->OperandsArray = new double[Count];
		for(unsigned int i = 0; i < Count; i++)
		{
			this->OperandsArray[i] = ops[i];
		}
	}
	else
	{
		double* temparray = new double[this->OperandsCount + Count];
		for(unsigned int i = 0; i < this->OperandsCount; i++)
		{
			temparray[i] = this->OperandsArray[i];
		}
		for(unsigned int i = this->OperandsCount; i < (this->OperandsCount + Count); i++)
		{
			temparray[i] = ops[i];
		}
		delete []this->OperandsArray;
		this->OperandsArray = temparray;
		this->OperandsCount += Count;
	}
}

ExpressionEvaluator::~ExpressionEvaluator(void)
{
	delete []this->OperandsArray;
}

unsigned int ExpressionEvaluator::getOperandsCount()
{
	return this->OperandsCount;
}

void ExpressionEvaluator::logToScreen()
{
	for (unsigned int i = 0; i < this->OperandsCount-1; i++)
	{
		std::cout << "Op" << i+1 << ", ";
	}
	std::cout << "Op" << this->OperandsCount << " : ";
	std::cout << this->formatNumber(this->OperandsArray[0]) << " " << this->sign << " ";
	for (unsigned int i = 1; i < this->OperandsCount-1; i++)
	{
		std::cout << this->formatNumber(this->OperandsArray[i]) << " " << this->sign << " ";
	}
	std::cout << this->formatNumber(this->OperandsArray[this->OperandsCount-1]);
	std::cout << std::endl << "-> " << this->formatNumber(this->Calculate());
}

void ExpressionEvaluator::logToFile(std::string filename)
{
	std::ofstream logFile(filename, std::ios_base::app | std::ios_base::out);
	for (unsigned int i = 0; i < this->OperandsCount; i++)
	{
		logFile << "Op" << i+1 << ", ";
	}
	logFile << "Op" << this->OperandsCount << " : ";
	logFile << this->formatNumber(this->OperandsArray[0]) << " " << this->sign;
	for (unsigned int i = 1; i < this->OperandsCount-1; i++)
	{
		logFile << this->formatNumber(this->OperandsArray[i]) << " " << this->sign;
	}
	logFile << this->formatNumber(this->OperandsArray[this->OperandsCount-1]);
	logFile << std::endl << "-> " << this->formatNumber(this->Calculate()) << std::endl;
	logFile.close();
}

std::string ExpressionEvaluator::formatNumber(double num)
{
	std::string returnstr;
	std::ostringstream convertor;
	if (num < 0) {returnstr = "(";}
	convertor << num;
	returnstr += convertor.str();
	if (num < 0) {returnstr += ")";} //костыли вы мои, костыли
	return returnstr;
}