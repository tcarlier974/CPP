/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:43:19 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/07 15:52:22 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

template< typename T >
T const &max(T const &a, T const &b)	{
	return (a > b ? a : b);
}

template< typename T >
T const &min(T const &a, T const &b) {
	return ( a >= b ? b : a);
}

template< typename T >
void swap(T &a, T&b) {
	T swap = b;
	b = a;
	a = swap;
}

#endif
