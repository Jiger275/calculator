#include "Lexer.h"
#include <cctype>

std::vector<std::string> Lexer::tokenize(const std::string& expression) const
{
	std::vector<std::string> tokens;
	size_t i = 0;

	while (i < expression.length())
	{
		if (std::isspace(expression[i]))
		{
			i++;
			continue;
		}
		if (std::isdigit(expression[i] || expression[i] == '.' || expression[i] == ','))
		{
			std::string number;
			while (i < expression.length() && (std::isdigit(expression[i] || expression[i] == '.' || expression[i] == ',')))
			{
				if (expression[i] == ',') number += '.';
				else number += expression[i];
				i++;
			}
			tokens.push_back(number);
		}
		else
		{
			tokens.push_back(std::string(1, expression[i]));
			i++;
		}
	}
	return tokens;
}