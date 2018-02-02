#include "StdAfx.h"
#include "Multiplier.h"
#include <random>
#include <algorithm>


Multiplier::Multiplier(void)
{
	this->sign = '*';
}

Multiplier::Multiplier(unsigned int N)
{
	this->sign = '*';
}

double Multiplier::Calculate()
{
	double temparik = this->OperandsArray[0];
	for(unsigned int i = 1; i < this->OperandsCount; i++)
	{
		temparik *= this->OperandsArray[i];
	}
	return temparik;
}

void Multiplier::shuffle()
{
	double minarrel;
	for(unsigned int i = 0; i < this->OperandsCount - 1; i++)
	{
		for(unsigned int j = i + 1; j < this->OperandsCount - 1; j++)
		{
			if((this->OperandsArray[i] > this->OperandsArray[j]) && (this->OperandsArray[j] < 0) && (this->OperandsArray[i] < 0))
			{
				minarrel = this->OperandsArray[j];
				this->OperandsArray[j] = this->OperandsArray[i];
				this->OperandsArray[i] = minarrel;
			}
		}
	}
}

void Multiplier::shuffle(unsigned int i, unsigned int j)
{
	double minarrel;
	for(unsigned int _i = i, _j = i; _i < j; _i++)
	{
		minarrel = this->OperandsArray[i];
		_j = _i-1;
		while((_j > 0) && (this->OperandsArray[_i] > minarrel))
		{
			this->OperandsArray[_j + 1] = this->OperandsArray[_j];
			_j--;
		}
		this->OperandsArray[_j + 1] = minarrel;
	}
}

Multiplier::~Multiplier(void)
{
}
