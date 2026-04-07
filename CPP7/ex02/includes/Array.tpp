/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 16:36:47 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/07 17:01:23 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template< typename T >
Array<T>::Array() : array(NULL), _size(0) {}

template< typename T >
Array<T>::Array(unsigned int n) : array(new T[n]()), _size(n) {}

template< typename T >
Array<T>::Array(const Array &copy) : array(new T[copy._size]()), _size(copy._size)
{
	size_t i = 0;

	while (i < copy._size)
	{
		array[i] = copy.array[i];
		i++;
	}
}

template< typename T >
Array<T>::~Array()
{
	delete [] array;
}

template< typename T >
Array<T> &Array<T>::operator=(const Array &a)
{
	if (this != a)
	{
		delete [] this->array;
		array = new T[a._size]();
		_size = a._size;
		size_t i = 0;
		while (i < _size)
		{
			array[i] = a.array[i];
			i++;
		}
	}
	return (*this);
}

template< typename T >
size_t Array<T>::size() {
	return(this->_size);
}

template< typename T >
T &Array<T>::operator[](unsigned int n)
{
	if (n >= _size)
	{
		throw std::out_of_range("out of bound");
	}
	return (array[n]);
}

template< typename T >
const T &Array<T>::operator[](unsigned int n) const 
{
	if (n >= _size)
	{
		throw std::out_of_range("out of bound");
	}
	return (array[n]);
}