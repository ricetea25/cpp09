#include <iostream>
#include <stack>
#include "RPN.hpp"

bool checkValidInput(const std::string& input)
{
	std::istringstream iss(input);
    std::string token;
	int i = 0;
    
    while (iss >> token)
	{
		int token_int;
		token_int = std::atoi(token.c_str());
		if (token_int > 9)
			return false;
		i++;
	}
	if (!(i % 2) || i < 3)
	{
		return false;
	}
	return true;
}

int main(int ac, char* av[]) {
	RPN reader;

	if (ac == 2)
	{
		if (!checkValidInput(av[1]))
		{
			std::cout << "Error: bad input" << std::endl;
			return (-1);
		}
		int ret;
		ret = reader.calculate(av[1]);
		std::cout << ret << std::endl;
	}
	else
		std::cout << "Error: use ./RPN <input>" << std::endl;
	return (0);
}