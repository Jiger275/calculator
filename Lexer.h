#ifndef __LEXER_H__
#define __LEXER_H__

#include <vector>
#include <string>

class Lexer 
{
public:
	std::vector<std::string> tokenize(const std::string& expression) const;
};

#endif // __LEXER_H__