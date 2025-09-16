#include "Calculator.h"
#include "Lexer.h"
#include "Parser.h"

#include <iostream>

int main(int argc, const char** argv) 
{
	std::string expression;
	std::cout << "Введите инфиксное выражение: ";
	std::getline(std::cin, expression);

	Lexer lexer;
	Parser parser;
	Calculator calculator;

	try 
	{
			auto tokens = lexer.tokenize(expression);
			auto postfix = parser.infixToPostfix(tokens);

			std::cout << "Постфиксное выражение: ";
			std::queue<std::string> temp = postfix;
			while (!temp.empty()) {
					std::cout << temp.front() << " ";
					temp.pop();
			}
			std::cout << std::endl;

			double result = calculator.evaluate(postfix);
			std::cout << "Результат: " << result << std::endl;
	} 
	catch (const std::exception& ex) 
	{
			std::cerr << ex.what() << std::endl;
	}

	return 0;
}