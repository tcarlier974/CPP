/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:18:31 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/06 16:20:51 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int	main( int ac, char **av)
{
	if ( ac != 2 )
		std::cout << "Error : Run like this : \n./convert [input]" << std::endl;
	else
		ScalarConverter::convert( av[1] );
	return ( 0 );
}