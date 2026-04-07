/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:43:19 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/07 17:04:38 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <exception>
# include <string>

template< typename T>
class Array
{
	private :
		T *array;
		unsigned int _size;
	public :
		Array();
		Array( unsigned int n );
		Array( const Array &copy );
		~Array();
		Array &operator=( const Array &a );
		T &operator[]( unsigned int n );
		const T &operator[]( unsigned int n ) const;

		size_t size( void );
};

#endif
