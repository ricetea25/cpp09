/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 19:48:04 by rteoh             #+#    #+#             */
/*   Updated: 2025/12/25 20:48:07 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

class RPN {
	private:
		std::stack<int> _stack;
	public:
		RPN();
		RPN(const RPN&);
		RPN& operator=(const RPN&);
		~RPN();
		int calculate(const std::string& expression);
		
};