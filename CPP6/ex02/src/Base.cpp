/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:57:08 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/06 19:29:53 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"


Base::~Base() {}

A::~A() {}
B::~B() {}
C::~C() {}

Base * generate(void)
{
	int random = rand() % 3;
	switch (random)
	{
		case 0:
			std::cout << "Generated instance of class A" << std::endl;
			return (new A());
		case 1:
			std::cout << "Generated instance of class B" << std::endl;
			return (new B());
		case 2:
			std::cout << "Generated instance of class C" << std::endl;
			return (new C());
		default:
			return (NULL);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identified class: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified class: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified class: C" << std::endl;
	else
		std::cout << "Unknown class type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Identified class: A" << std::endl;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Identified class: B" << std::endl;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Identified class: C" << std::endl;
	}
	catch (...) {}
}
