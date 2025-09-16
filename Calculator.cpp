#include "Calculator.h"
#include <stack>
#include <queue>
#include <cctype>
#include <cmath>

Calculator::Calculator() {}

double Calculator::evaluate(std::queue<std::string> postfix)
{
	std::stack<double> values;
	char variable = '\0';

	while (!postfix.empty())
	{
		std::string token = postfix.front();
		postfix.pop();

		if (isNumber(token))
		{
			values.push(std::stod(token));
		}
		else if (token.length() == 1 && std::isalpha(token[0]) && postfix.front() == "=")
		{
			postfix.pop();
			variable = token[0];
		}
		else if (token.length() == 1)
		{
			double right = values.top(); values.pop();
			double left = values.top(); values.pop();
			char op = token[0];
			switch (op)
			{
				case '+': 
					values.push(left + right);
					break;
				case '-':
					values.push(left - right);
					break;			
				case '*':
					values.push(left * right);
					break;
				case '/':
					if (right == 0) 
					{
						throw std::runtime_error("Ошибка: Деление на ноль");
					}
					values.push(left / right);
					break;	
				case '^':
					values.push(pow(left, right));
					break;
				default:
					throw std::runtime_error("Ошибка: Неизвестный оператор");
					break;
			}
		}
	}

	if (variable != '\0')
	{
		variables[variable] = values.top();
	}

	return values.top();
}

#include <iostream>
void Calculator::printVariables() const
{
	for (const auto& var : variables)
	{
		std::cout << var.first << " = " << var.second << std::endl;
	}
}

bool Calculator::isNumber(const std::string& str) const
{
	try
	{
		std::size_t pos;
		std::stod(str, &pos);
		return pos == str.length();
	}
	catch(...)
	{
		return false;
	}
}