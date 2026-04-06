/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:37:13 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/06 16:37:24 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	private:
		~Serializer();
		Serializer();
		Serializer( std::string );
		Serializer( Serializer const &copy );
		Serializer &operator=( Serializer const &instance );

	public:
		static uintptr_t serialize( Data *ptr );
		static Data* deserialize( uintptr_t raw );
};

#endif