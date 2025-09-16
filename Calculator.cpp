#include "Calculator.h"
#include <stack>
#include <queue>
#include <cctype>
#include <cmath>



Calculator::Calculator() {}

double Calculator::evaluate(std::queue<std::string> postfix) const
{
	std::stack<double> values;

	while (!postfix.empty())
	{
		std::string token = postfix.front();
		postfix.pop();

		if (isNumber(token))
		{
			values.push(std::stod(token));
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
	return values.top();
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