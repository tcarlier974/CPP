/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 20:07:02 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/06 16:24:26 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(std::string src)
{
	(void)src;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

bool	parse(std::string src)
{
	if (src == "nan" ||
		src == "nanf" ||
		src == "+inf" ||
		src == "+inff" ||
		src == "-inf" ||
		src == "-inff")
		return (true);
	if ((src.length() == 3 && src[0] == '\'' && isprint(src[1]) && src[2] == '\'') ||
		(src.length() == 1 && isprint(src[0])))
		return (true);
	bool digit = false;
	size_t i = 0;
	if (src[i] == '+' || src[i] == '-')
		i++;
	while (i < src.length() && std::isdigit(src[i]))
	{
		i++;
		digit = true;
	}
	if ( i < src.length() && src[i] == '.')
	{
		i++;
		while (i < src.length() && std::isdigit(src[i]))
		{
			i++;
			digit = true;
		}
	}
	if (!digit)
		return (false);
	if ((i == src.length() - 1 && src[i] == 'f') || i == src.length())
		return (true);
	return (false);
}

void	convert_for_char(char c, std::string &toChar, int &toInt, float &toFloat, double &toDouble)
{
	toChar = "'";
	toChar += c;
	toChar += "'";
	toInt = static_cast<int>(c);
	toFloat = static_cast<float>(c);
	toDouble = static_cast<double>(c);
}

void	print(std::string toChar, int toInt, float toFloat, double toDouble, bool i)
{
	std::cout << "char : " << toChar << std::endl; 
	std::cout << "int : ";
	if (i)
		std::cout << "impossible" << std::endl;
	else
		std::cout << toInt << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(1) << toFloat << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << toDouble << std::endl;
}

void ScalarConverter::convert(const std::string& src)
{
	if (!parse(src))
	{
		std::cerr << "Error: Invalid src." << std::endl;
		return;
	}
	std::string toChar = "impossible";
	int		toInt = 0;
	float	toFloat = 0.0f;
	double	toDouble = 0.0;
	bool	i = false;

	if ( (src.length() == 3 && src[0] == '\'' && src[2] == '\'' && std::isprint(src[1])) )
		convert_for_char( src[1], toChar, toInt, toFloat, toDouble );
	else if ( src.length() == 1 && std::isprint(src[0]) && !std::isdigit(src[0]) )
		convert_for_char( src[0], toChar, toInt, toFloat, toDouble );
	else
	{
		toDouble = std::strtod( src.c_str(), NULL );
		toFloat = static_cast<float>( toDouble );

		if ( std::isinf(toFloat) && !std::isinf(toDouble) )
			toDouble = toFloat;

		if ( toDouble < INT_MIN || toDouble > INT_MAX || std::isnan(toDouble) || std::isinf(toDouble) )
			i = true;
		else
			toInt = static_cast<int>( toDouble );

		if ( i || toInt < 0 || toInt > 127 )
			toChar = "impossible";
		else if ( toInt < 32 || toInt > 126 )
			toChar = "Non displayable";
		else
		{
			toChar = "'";
			toChar += static_cast<char>( toInt );
			toChar += "'";
		}
	}
	print(toChar, toInt, toFloat, toDouble, i);
}