/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 03:59:03 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/15 06:11:22 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <stdexcept>
# include <ctime>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;
        double _vectorTime;
        double _dequeTime;

        
        void mergeInsertSortVector(std::vector<int>& vec);
        void mergeInsertSortDeque(std::deque<int>& deq);
        void printVector() const;
        void printDeque() const;
        void printBefore() const;
        void print() const;
        void printTime() const;

    public:
        PmergeMe();
        PmergeMe(char** argv);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        std::vector<int> buildInsertOrder(int n);

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