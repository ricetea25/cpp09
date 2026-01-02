/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 22:32:34 by rteoh             #+#    #+#             */
/*   Updated: 2025/12/15 15:22:15 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cout << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }
    
    try {
        BitcoinExchange exchange;
        exchange.ProcessInputFile(argv[1]);
    } 
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}