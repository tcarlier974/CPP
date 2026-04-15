/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 02:47:50 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/15 03:56:25 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        this->_stack = other._stack;
    return *this;
}

RPN::~RPN() {}

void RPN::plus()
{
    int a;
    int b;
    if (this->_stack.size() < 2)
        throw EmptyStack();
    a =_stack.top();
    _stack.pop();
    b =_stack.top();
    _stack.pop();
    _stack.push(b + a);
}

void RPN::minus()
{
    int a;
    int b;
    if (this->_stack.size() < 2)
        throw EmptyStack();
    a =_stack.top();
    _stack.pop();
    b =_stack.top();
    _stack.pop();
    _stack.push(b - a);
}

void RPN::divide()
{
    int a;
    int b;
    if (this->_stack.size() < 2)
        throw EmptyStack();
    a =_stack.top();
    _stack.pop();
    b =_stack.top();
    _stack.pop();
    _stack.push(b / a);
}

void RPN::multiply()
{
    int a;
    int b;
    if (this->_stack.size() < 2)
        throw EmptyStack();
    a =_stack.top();
    _stack.pop();
    b =_stack.top();
    _stack.pop();
    _stack.push(b * a);
}

RPN::RPN() {}

RPN::RPN(const std::string& expression)
{
    std::stringstream ss(expression);
    std::string token;
    int n;

    while (std::getline(ss, token, ' '))
    {
        if (token.empty())
            continue;
        if ( ((token.length() == 1 && isdigit(token[0])) ||
				(token.length() == 2 && token[0] == '-' && isdigit(token[1]))) )
        {
            std::stringstream(token) >> n;
            _stack.push(n);
        }
        else if (token == "+")
            plus();
        else if (token == "-")
            minus();
        else if (token == "*")
            multiply();
        else if (token == "/")
            divide();
        else
            throw InvalidArg();
    }
    if (_stack.size() != 1)
        throw InvalidArg();
    std::cout << _stack.top() << std::endl;
}