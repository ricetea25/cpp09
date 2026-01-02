/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 22:32:32 by rteoh             #+#    #+#             */
/*   Updated: 2025/12/25 13:32:04 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <exception>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _database;
		std::string first_date;
		std::string last_date;
		bool is_first_date;
		
		void LoadBitcoinDB(const std::string& filename);
		std::string _trim(const std::string& str) const;
		bool CheckValidDate(const std::string& str_date);
		bool CheckValidValue(const std::string& str_value, double& result);
		float GetBitcoinPrice(const std::string& target_date);
		bool	is_empty_line(const std::string &line);

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& filename);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void ProcessInputFile(const std::string& filename);
		
		class BadFile : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error: could not open file");
				}
		};
		class BadDBColumnFormat : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error: invalid database format");
				}
		};
		class BadInputColumnFormat : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error: invalid input format");
				}
		};
		class InvalidRate : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error: invalid exchange rate in database");
				}
		};
};

#endif