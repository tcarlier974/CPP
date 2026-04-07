/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 17:29:57 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/07 18:10:58 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <algorithm>
# include <iterator>
# include <vector>

class Span
{
	private :
		std::vector<int> _v;
		unsigned int _size;
	public :

		Span();
		Span(unsigned int n);
		Span(Span const &copy);
		Span &operator=(Span const &a);
		~Span();
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		class TooManyNumber : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("This array is already full");
				}
		};
		class NotFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("There is not enough number to find a span");
				}
		};
};

#endif