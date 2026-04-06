/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:36:59 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/06 16:37:04 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::~Serializer() {};

Serializer::Serializer() {};

Serializer::Serializer( std::string ) {};

Serializer::Serializer( Serializer const &copy )
{
	*this = copy;
};

Serializer &Serializer::operator=( Serializer const &instance )
{
	(void)instance;
	return ( *this );
}

uintptr_t Serializer::serialize( Data* ptr )
{
	uintptr_t ser_data = reinterpret_cast<uintptr_t>(ptr);
	return ( ser_data );
}

Data *Serializer::deserialize( uintptr_t raw )
{
	Data *ptr_data = reinterpret_cast<Data*>(raw);
	return ( ptr_data );
}