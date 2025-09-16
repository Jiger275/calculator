#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <string>
#include <queue>

class Calculator 
{
private:
	bool isNumber(const std::string& str) const;
public: 
	Calculator();
	double evaluate(std::queue<std::string> postfix) const;
};

#endif // __CALCULATOR_H__