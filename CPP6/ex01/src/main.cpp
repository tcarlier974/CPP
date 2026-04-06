/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:38:37 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/06 16:40:11 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

void printData( const Data* data, const std::string& label )
{
	std::cout << "\n********** " << label << " **********" << std::endl;
	std::cout << "->> a: " << data->a << std::endl;
	std::cout << "->> b: " << data->b << std::endl;
	std::cout << "->> c: " << data->c << std::endl;
	std::cout << "->> world : " << data->world << std::endl;
	std::cout << "->> wordle : " << data->wordle << std::endl;
	std::cout << "->> word : " << data->word << std::endl;
}

int main( void )
{
	Data data = {
		888,					 
		777,					 
		555,					 
		"alert__reaction",		 
		"couple__grown",		 
		"jumpy___cream"			 
	};

	printData( &data, "Before Serialization" );

	uintptr_t raw = Serializer::serialize( &data );
	std::cout << "\033[1;33m\nSerialized uintptr_t: " << "\033[0m" << raw << std::endl;

	Data* ptr = Serializer::deserialize( raw );
	printData( ptr, "After Deserialization" );

	return ( 0 );
}