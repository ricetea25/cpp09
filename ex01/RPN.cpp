
#include "RPN.hpp"


RPN::RPN() : _stack()
{	
}

RPN::RPN(const RPN &other) : _stack(other._stack)
{
}

RPN &RPN::operator=(RPN const &other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

RPN::~RPN()
{
}

template <typename T>
void printStack(std::stack<T> s)
{
    std::cout << "Stack (top to bottom): ";
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

int RPN::calculate(const std::string& expression)
{
	std::istringstream iss(expression);
	std::string token;

	
	while (iss >> token)
	{
		if (token.length() == 1 && std::isdigit(token[0]))
		{
			_stack.push(token[0] - '0');
		}
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (_stack.size() < 2)
			{
				std::cerr << "not enough tokens to run operand\n";
				return -1;
			}


			int b = _stack.top(); _stack.pop();
			int a = _stack.top(); _stack.pop();

			if (token == "+") 
				_stack.push(a + b);
			else if (token == "-")
				_stack.push(a - b);
			else if (token == "*") 
				_stack.push(a * b);
			else if (token == "/")
			{
				if (b == 0)
				{
					std::cerr << "Error: cant divide with zero" << std::endl;
					return -1;
				}
				_stack.push(a / b);
			}
			else
			{
				std::cerr << "Error: i dont know what this token is \"" << token[0] << "\"" << std::endl;
				exit (1);
			}
			
		}
		else
		{
			std::cerr << "Error: i dont know what this token is \"" << token[0] << "\"" << std::endl;
			exit (1);
		}
	}
	return _stack.top();
}