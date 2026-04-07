/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 20:06:54 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/07 18:13:19 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <limits>
# include <cstdlib>
# include <cmath>
# include <cerrno>
# include <climits>
# include <cctype>

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