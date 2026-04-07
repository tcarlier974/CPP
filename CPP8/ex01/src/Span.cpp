/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:04:49 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/07 18:27:58 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int n) : _size(n) {}

Span::~Span() {}

Span::Span(Span const &copy)
{
	*this = copy;
}

Span &Span::operator=(Span const &a)
{
	if (this != &a)
	{
		this->_size = a._size;
		this->_v = a._v;
	}
	return (*this);
}

void Span::addNumber(int n)
{
	if (this->_v.size() >= this->_size)
	{
		throw TooManyNumber();
	}
	this->_v.push_back(n);
}

int Span::shortestSpan()
{
	if (_size <= 1)
		throw NotFoundException();
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	unsigned int i = 2;
	while (i < _size)
	{
		if (min > tmp[i] - tmp[i - 1])
			min = tmp[i] - tmp[i - 1];
		i++;
	}
	return (min);
};

int Span::longestSpan()
{
	if (_size <= 1)
		throw NotFoundException();
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}