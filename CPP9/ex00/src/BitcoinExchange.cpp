/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:26:13 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/15 02:23:55 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    loadData();
}

BitcoinExchange::BitcoinExchange(std::string param)
{
    loadData();
    (void)param;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &copy)
{
    if (this != &copy)
    {
        this->data = copy.data;
    }
    return *this;
}

void    BitcoinExchange::printExchange(std::string date, double value)
{
    std::map<std::string, double>::iterator it = data.lower_bound(date);
    if (it == data.end())
    {
        --it;
    }
    if (it->first > date && it != data.begin())
    {
        --it;
    }
    std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}

bool BitcoinExchange::isValidDate(std::string date)
{
    if (date.length() != 11 || date[4] != '-' || date[7] != '-' || date[10] != ' ')
    {
        std::cout << "Error: Invalid date format => " << date << std::endl;
        return false;
    }
    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);
    int year, month, day;
    try
    {
        std::istringstream yearStream(yearStr);
        std::istringstream monthStream(monthStr);
        std::istringstream dayStream(dayStr);
        if (!(yearStream >> year) || !(monthStream >> month) || !(dayStream >> day))
        {
            std::cout << "Error: Invalid date format => " << date << std::endl;
            return false;
        }
    }
    catch (const std::exception &e)
    {
        return false;
    }
    if (month < 1 || month > 12 || day < 1 || day > 31)
    {
        std::cout << "Error: Invalid date format => " << date << std::endl;
        return false;
    }
    return true;
}

double BitcoinExchange::isValidValue(std::string value)
{
    double val = strtod(value.c_str(), NULL);
    if (val < 0.0 || val > 1000.0 || !val)
    {
        std::cout << "Error: invalid value => " << value << std::endl;
        return -1.0;
    }
    return val;
}

void    BitcoinExchange::loadData(void)
{
    std::ifstream file("data.csv");
    if (!file)
    {
        throw FileException();
    }
    std::string line;

    std::getline(file, line);
    if (line != "date,exchange_rate")
    {
        throw FileNoTitleException();
    }
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date;
        std::string value;
        if (std::getline(iss, date, ',') && std::getline(iss, value))
        {
            double price;
            std::istringstream valueStream(value);
            if (!(valueStream >> price))
            {
                throw FilePriceException();
            }
            data[date] = price;
        }
    }
    file.close();
}

void BitcoinExchange::exec(std::string param)
{
    std::ifstream file(param.c_str());
    if (!file.is_open())
    {
        throw BitcoinExchange::FileException();
    }
    std::string line;
    std::getline(file, line);
    if (line != "date | value")
    {
        throw BitcoinExchange::FileLineException();
    }
    while (getline(file, line))
    {
        std::istringstream ss(line);
        std::string date, value;
        if (std::getline(ss, date, '|') && std::getline(ss, value))
        {
            if (!isValidDate(date))
            {
                continue;
            }
            double price = isValidValue(value);
            if (price < 0.0)
                continue;
            printExchange(date, price);
        }
		if ( date.empty() || value.empty() )
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
    }
    file.close();
}