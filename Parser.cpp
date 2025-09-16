#include "Parser.h"

#include <unordered_map>
#include <stack>
#include <string>

#include <iostream>

static const std::unordered_map<char, int> precedence = {
	{'+', 1},
	{'-', 1},
	{'*', 2},
	{'/', 2},
	{'^', 3}
};

std::queue<std::string> Parser::infixToPostfix(const std::vector<std::string>& tokens) const
{
	std::stack<char> operators;
	std::queue<std::string> output;

	if (tokens.empty()) 
	{
			throw std::runtime_error("Ошибка: Пустое выражение");
	}

	std::size_t i = 0;
	if (tokens[1] == "=")
	{
		if (tokens.size() < 3 || !std::isalpha(tokens[0][0]) || tokens[0].size() != 1)
		{
			throw std::runtime_error("Ошибка: Неверный формат присваивания");
		}
		operators.push('=');
		operators.push(tokens[0][0]);	
		i = 2;
	} 

	for (; i < tokens.size(); i++)
	{
		std::string token = tokens[i];
		if (std::isdigit(token[0]))
		{
			output.push(token);
		}
		else if (precedence.count(token[0]))
		{
			while (!operators.empty() && precedence.count(operators.top()) && precedence.at(token[0]) <= precedence.at(operators.top()))
			{
				output.push(std::string(1, operators.top()));
				operators.pop();
			}
			operators.push(token[0]);
		}
		else if (token == "(")
		{
			operators.push('(');
		}
		else if (token == ")")
		{
			while (!operators.empty() && operators.top() != '(')
			{
				output.push(std::string(1, operators.top()));
				operators.pop();
			}
			if (operators.empty() || operators.top() != '(')
			{
				throw std::runtime_error("Ошибка: Несбалансированные скобки");
			}
			operators.pop();
		}
		else
		{
			if (token != " " && token != "\t" && token != "\n")
			{
				throw std::runtime_error("Ошибка: Неизвестный символ '" + token + "'");
			}
		}
	}

	while (!operators.empty()) 
	{
			output.push(std::string(1, operators.top()));
			operators.pop();
	}

	return output;
}