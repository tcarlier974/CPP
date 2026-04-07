/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:43:19 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/07 16:00:16 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template< typename T, typename F>
void iter(T * address, const size_t l, F fonc) {
	size_t i = 0;

	while (i < l)
	{
		fonc(address[i]);
		i++;
	}
}

#endif
