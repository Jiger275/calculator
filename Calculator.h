#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <string>
#include <queue>
#include <map>

class Calculator 
{
private:
	bool isNumber(const std::string& str) const;
	std::map<char, int> variables;
	
public: 
	Calculator();
	double evaluate(std::queue<std::string> postfix);
	void printVariables() const;
};

#endif // __CALCULATOR_H__