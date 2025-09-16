#ifndef __PARSER_H__
#define __PARSER_H__

#include <string>
#include <queue>
#include <vector>
#include <map>

class Parser 
{
public: 
	std::queue<std::string> infixToPostfix(const std::vector<std::string>& tokens) const;
};

#endif // __PARSER_H__