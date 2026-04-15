/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 02:48:29 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/15 03:41:49 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <stdexcept>
# include <sstream>

class RPN
{
    private:
        std::stack<int> _stack;

    public:
        RPN();
        RPN(const std::string& expression);
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        void plus();
        void minus();
        void multiply();
        void divide();

        class EmptyStack : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Error: Not enough operands in the stack";
                }
        };
        class InvalidArg : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Error: Invalid Argument";
                }
        };
};

#endif