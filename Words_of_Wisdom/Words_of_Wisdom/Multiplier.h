#pragma once
#include "IShuffle.h"
#include "expressionevaluator.h"
class Multiplier :
	public ExpressionEvaluator, public IShuffle
{
public:
	Multiplier(void);
	Multiplier(unsigned int N);
	double Calculate();
	void shuffle();
	void shuffle(unsigned int i, unsigned int j);
	~Multiplier(void);
};

