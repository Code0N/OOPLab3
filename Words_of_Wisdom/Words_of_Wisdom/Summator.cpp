#include "StdAfx.h"
#include "Summator.h"


Summator::Summator(void)
{
	this->sign = '+';
}

Summator::Summator(unsigned int N) : ExpressionEvaluator(N)
{
	this->sign = '+';
}

double Summator::Calculate()
{
	double temparik = 0;
	for(unsigned int i = 0; i < this->OperandsCount; i++)
	{
		temparik += this->OperandsArray[i];
	}
	return temparik;
}


Summator::~Summator(void)
{
}
