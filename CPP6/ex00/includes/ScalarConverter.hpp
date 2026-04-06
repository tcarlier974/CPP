/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 20:06:54 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/06 15:24:59 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <limits>
# include <cstdlib>
# include <cmath>	// for isnan, isinf
# include <cerrno>	// for errno, ERANGE
# include <climits>	// for INT_MAX, INT_MIN
# include <cctype>	// for isprint, isdigit

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(std::string src);
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		virtual ~ScalarConverter();

	public:
		static void convert(const std::string& src);
	
};

#endif