/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:14:55 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/06 19:27:18 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"

int main()
{
	Base* base = generate();
	identify(base);
	identify(*base);
	delete base;
	Base* base2 = generate();
	identify(base2);
	identify(*base2);
	delete base2;
	return 0;
}