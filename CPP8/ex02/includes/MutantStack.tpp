/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:59:44 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/08 16:21:50 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template< typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template< typename T>
MutantStack<T>::MutantStack(std::string param) : std::stack<T>() 
{
	(void)param;
}

template< typename T>
MutantStack<T>::~MutantStack() {}

template< typename T>
MutantStack<T>::MutantStack(MutantStack const &copy) : std::stack<T>(copy) {}

template< typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &a)
{
	if (this != &a)
	{
		std::stack<T>::operator=(a);
	}
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return ( this->c.rend() );
}

