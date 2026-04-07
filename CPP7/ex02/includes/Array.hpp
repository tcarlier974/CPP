/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:43:19 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/07 18:11:34 by tcarlier         ###   ########.fr       */
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
		Array( Array const &copy );
		~Array();
		Array &operator=( Array const &a );
		T &operator[]( unsigned int n );
		const T &operator[]( unsigned int n ) const;

		size_t size( void );
};

#endif
