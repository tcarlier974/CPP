/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 17:42:46 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/07 18:29:32 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

int main()
{
	std::cout << "\033[33m" << "Test vector container\n"<< "\033[0m";
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	try
	{
		sp.addNumber(11);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\033[33m" << "Test vector range\n"<< "\033[0m";
	Span sp2 = Span(100);
	std::vector<int> v;
	std::srand(time(NULL));
	for ( int i = 0; i < 100; i++ )
	{
		int random_int = rand() % 1000000;
		sp2.addNumber(random_int);
	}
	try
	{
		std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\033[33m" << "Test vector large range\n"<< "\033[0m";
	Span sp3 = Span(100000);
	std::vector<int> v2;
	std::srand(time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		
		int random_int = rand() % 1000000000;
		sp3.addNumber(random_int);
	}
	try
	{
		std::cout << "shortest span: " << sp3.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp3.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}