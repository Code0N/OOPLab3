#pragma once
#include <iostream>
#include <string>

class ILoggable
{
public:
	virtual void logToScreen() = 0;
	virtual void logToFile(std::string filename) = 0;
protected:
	virtual std::string formatNumber(double num) = 0;
};