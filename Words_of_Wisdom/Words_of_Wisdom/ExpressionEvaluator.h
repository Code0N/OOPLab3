#pragma once
#include "ILoggable.h"
#include <string>
class ExpressionEvaluator :
	public ILoggable
{
public:
	ExpressionEvaluator(void);
	ExpressionEvaluator(unsigned int N);
	virtual void logToScreen();
	virtual void logToFile(std::string filename);
	void setOperand(unsigned int pos, double value);
	void setOperand(double ops[], unsigned int Count, bool erase);
	unsigned int getOperandsCount();
	virtual double Calculate() = 0;
	virtual ~ExpressionEvaluator(void);
protected:
	std::string formatNumber(double num);
	unsigned int OperandsCount;
	double* OperandsArray;
	char sign;
};

