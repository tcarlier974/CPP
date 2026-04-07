/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 17:29:57 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/07 17:45:16 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <algorithm>
# include <iterator>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Number not found");
		}
};

template< typename T >
typename T::iterator easyfind(T array, int n)
{
	typename T::iterator it = std::find(array.begin(), array.end(), n);
	if ( it == array.end())
		throw NotFoundException();
	return (it);
}

#endif