#pragma once
#include "expressionevaluator.h"
#include "IShuffle.h"
class CustomExpressionEvaluator :
	public ExpressionEvaluator, public IShuffle
{
public:
	CustomExpressionEvaluator(void);
	CustomExpressionEvaluator(unsigned int N);
	virtual double Calculate();
	void shuffle();
	void shuffle(unsigned int i, unsigned int j);
	void logToScreen();
	virtual void logToFile(std::string filename);
	~CustomExpressionEvaluator(void);
};

