/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 22:32:25 by rteoh             #+#    #+#             */
/*   Updated: 2026/01/03 16:03:14 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() : first_date(""), last_date(""), is_first_date(true)
{
	LoadBitcoinDB("data.csv");
	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database), first_date(other.first_date), last_date(other.last_date)
{
}

BitcoinExchange::BitcoinExchange(const std::string& filename)
{
	LoadBitcoinDB(filename);
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
	if (this != &other)
		_database = other._database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}


std::string BitcoinExchange::_trim(const std::string& str) const
{
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}


void BitcoinExchange::LoadBitcoinDB(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw BadFile();
	
	std::string line;
	
	std::getline(file, line);
	if (_trim(line) != "date,exchange_rate")
		throw BadDBColumnFormat();

	is_first_date = true;
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		size_t comma_pos = line.find(',');
		if (comma_pos == std::string::npos)
			continue;
		std::string date = _trim(line.substr(0, comma_pos));
		if (is_first_date)
		{
			first_date = date;
			is_first_date = false;
		}
		last_date = date;
		
		std::string rate_str = _trim(line.substr(comma_pos + 1));
		
		std::istringstream ss(rate_str);
		float rate;
		std::string leftover;
		if (!(ss >> rate) || (ss >> leftover))
			throw InvalidRate();
		//need a valid date checker here
		//year-month-day
		
		_database[date] = rate;
	}

}

bool BitcoinExchange::CheckValidDate(const std::string& str_date)
{
	//follow format
    if (str_date.length() != 10 || str_date[4] != '-' || str_date[7] != '-')
	{
		std::cout << "Error: bad input date => " << str_date << std::endl;
		return false;
	}
    
    for (size_t i = 0; i < 10; ++i) 
	{
        if (i == 4 || i == 7) 
			continue;
        if (!std::isdigit(str_date[i]))
		{
			std::cout << "Error: bad input date => " << str_date << std::endl;
            return false;
		}
    }
    //seperate the string
    int year = std::atoi(str_date.substr(0, 4).c_str());
    int month = std::atoi(str_date.substr(5, 2).c_str());
    int day = std::atoi(str_date.substr(8, 2).c_str());
    
    if (month < 1 || month > 12 || day < 1 || day > 31)
	{
		std::cout << "Error: bad input date => " << str_date << std::endl;
		return false;
	}
    //check month days whether its valid
    if (month == 2)
	{
        bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (leap ? 29 : 28)) 
		{
			std::cout << "Error: bad input date => " << str_date << std::endl;
			return false;
		}
    } 
	else if (month == 4 || month == 6 || month == 9 || month == 11) 
	{
        if (day > 30) 
		{
			std::cout << "Error: bad input date => " << str_date << std::endl;
			return false;
		}
    }
    
    if (!first_date.empty()) 
	{
        if (str_date < first_date)
		{
			std::cout << "Error: bad input date => " << str_date << std::endl;
			return false;
		}
    }
    
    return true;
}


bool BitcoinExchange::CheckValidValue(const std::string& str_value, double& result)
{
	std::string trim_value = _trim(str_value);
	std::istringstream ss(trim_value);
	// std::cout << str_value << std::endl;
	//will fail if its a string
	if (!(ss >> result))
	{
		std::cout << "Error: bad input for value =>" << ss.str() << std::endl;
		return false;
	}
	// std::cout << result << std::endl;
	char leftover;
	while (ss.get(leftover))
	{
		if (!std::isspace(leftover))
		{
			std::cout << "Error: bad input for value =>" << str_value << std::endl;
			return false;
		}
	}
	if (result > 1000) 
	{
		std::cout << "Error: too large a number. => " << result << std::endl;
		return false;
	}
	else if (result < 0)
	{
		std::cout << "Error: not a positive number. => " << result << std::endl;
		return false;
	}
	return true;
}

float BitcoinExchange::GetBitcoinPrice(const std::string& target_date)
{
    if (_database.empty())
        return -1.0f;
    
    std::map<std::string, float>::iterator it = _database.find(target_date);
	//will find it if its in
	//if its not in it would return the .end() of the container
	//this is exact date found
    if (it != _database.end()) {
        return it->second;
    }
    
    it = _database.lower_bound(target_date);
    
    if (it == _database.begin()) {
        return -0.0f;
    }
    
    --it;
    return it->second;
}

bool BitcoinExchange::is_empty_line(const std::string& line)
{
	if (line.empty())
		return true;

	for (size_t i = 0; i < line.length(); ++i) {
		if (!std::isspace(static_cast<unsigned char>(line[i])))
			return false;
	}
	return true;
}

void BitcoinExchange::ProcessInputFile(const std::string& filename) 
{
	
	std::map<std::string, float> _tofind;
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw BadFile();
	
	std::string line;
	while (std::getline(file, line)) 
	{
		bool has_content = false;
		for (size_t i = 0; i < line.length(); ++i) {
			if (!std::isspace(line[i])) {
				has_content = true;
				break;
			}
		}
		if (has_content)
			break;
	}
	//trim
	
	if (_trim(line) != "date | value")
		throw BadInputColumnFormat();
	while (std::getline(file, line))
	{
		if (is_empty_line(line))
			continue;
		
		size_t	pipe_pos = line.find("|");
		if (pipe_pos == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		std::string date = _trim(line.substr(0, pipe_pos));
		std::string value_str = _trim(line.substr(pipe_pos + 1));
		// std::cout << date;
		// std::cout << value_str;
		
		if (CheckValidDate(date))
		{
			double value_float;
			float total_value;
			if (CheckValidValue(value_str, value_float))
			{
				float btc_price = GetBitcoinPrice(date);
				total_value = value_float * btc_price;
				std::cout << date << " => " << value_str << " = " << total_value << std::endl;
			}
		}
	}
	

	
}