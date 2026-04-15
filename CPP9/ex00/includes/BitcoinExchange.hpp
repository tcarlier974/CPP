/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:25:52 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/15 02:07:51 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <exception>
# include <iostream>
# include <string>
# include <list>
# include <map>
# include <fstream>
# include <sstream>
# include <cstdlib>

class BitcoinExchange
{
	public:

		BitcoinExchange();
		BitcoinExchange(std::string param);
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &copy);
		BitcoinExchange &operator=(BitcoinExchange const &copy);

		void loadData();
		bool isValidDate(std::string date);
		double isValidValue(std::string value);
		void exec(std::string param);
		void printExchange(std::string date, double value);

		class FileException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Error: could not open file.";
				}
		};
		class FileNoTitleException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Error: Invalid line format. Expected 'date,exchange_rate'";
				}
		};
		class FileLineException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Error: Invalid line format. Expected 'date | value'";
				}
		};
		class FilePriceException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Error: Invalid price format. Expected a number between 0.0 and 1000.0";
				}
		};
		class FileDateException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Error: Invalid date format. Expected YYYY-MM-DD";
				}
		};
	private:
		std::map<std::string, double> data;
};

#endif