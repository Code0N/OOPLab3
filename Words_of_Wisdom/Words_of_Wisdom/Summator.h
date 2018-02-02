#pragma once
#include "expressionevaluator.h"
class Summator :
	public ExpressionEvaluator
{
public:
	Summator(void);
	Summator(unsigned int N);
	double Calculate();
	~Summator(void);
};

