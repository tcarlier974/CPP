/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 03:58:59 by tcarlier          #+#    #+#             */
/*   Updated: 2026/04/15 06:18:42 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        this->_vector = other._vector;
        this->_deque = other._deque;
    }
    return *this;
}

PmergeMe::PmergeMe() {}

void PmergeMe::printTime() const{
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << _vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << _dequeTime << " us" << std::endl;
}

void PmergeMe::print() const{
    std::cout << "Sorted Vector: ";
    printVector();
    std::cout << "Sorted Deque: ";
    printDeque();
    printTime();
}

void PmergeMe::printBefore() const{
    std::cout << "Before: ";
    printVector();
}

void PmergeMe::printVector() const
{
    for (size_t i = 0; i < _vector.size(); ++i)
    {
        std::cout << _vector[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printDeque() const
{
    for (size_t i = 0; i < _deque.size(); ++i)
    {
        std::cout << _deque[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<int> PmergeMe::buildInsertOrder(int size) {
    std::vector<int> order;

    if (size <= 1) return order;
    std::vector<int> jacob;
    int prev = 1;
    int curr = 3;
    jacob.push_back(curr);
    while (curr < size + 2) {
        int next = curr + 2 * prev;
        jacob.push_back(next);
        prev = curr;
        curr = next;
    }
    int lastInserted = 0;

    for (size_t i = 0; i < jacob.size(); ++i) {
        int jIndex = jacob[i] - 1; 
        if (jIndex >= size) {
            jIndex = size - 1;
        }
        int currentToInsert = jIndex;
        while (currentToInsert > lastInserted) {
            order.push_back(currentToInsert);
            currentToInsert--;
        }
        lastInserted = jIndex;
        if (lastInserted == size - 1) {
            break;
        }
    }
    return order;
}


//=========================< VECTOR SORT >=========================


void PmergeMe::mergeInsertSortVector(std::vector<int>& vec)
{
    if (vec.size() <= 1)
        return;
    std::vector<std::pair<int, int> > pair;
    std::vector<int> winners;

    bool odd = (vec.size() % 2 != 0);
    int straggler = -1;
    if (odd)
        straggler = vec[vec.size() - 1];
    for (size_t i = 0; i < vec.size() / 2; ++i)
    {
        int a = vec[i * 2];
        int b = vec[(i * 2) +1];
        if (a < b)
            std::swap(a, b);
        pair.push_back(std::make_pair(a, b));
        winners.push_back(a);
    }
    mergeInsertSortVector(winners);
    std::vector<int> MainChain;
    std::vector<int> Losers;
    for (size_t i = 0; i < winners.size(); ++i)
    {
        MainChain.push_back(winners[i]);
        for (size_t j = 0; j < pair.size(); ++j)
        {
            if (pair[j].first == winners[i]) {
                Losers.push_back(pair[j].second);
                break;
            }
        }
    }
    if (!Losers.empty())
        MainChain.insert(MainChain.begin(), Losers[0]);
    std::vector<int> InsertOrder = buildInsertOrder(Losers.size());
    if (odd) {
        Losers.push_back(straggler);
        InsertOrder.push_back(Losers.size() - 1);
    }
    for (size_t i = 0; i < InsertOrder.size(); ++i)
    {
        int index = InsertOrder[i];
        int value = Losers[index];
        std::vector<int>::iterator it = std::lower_bound(MainChain.begin(), MainChain.end(), value);
        MainChain.insert(it, value);
    }
    vec = MainChain;
}

//=========================< DEQUE SORT >=========================

void PmergeMe::mergeInsertSortDeque(std::deque<int>& vec)
{
    if (vec.size() <= 1)
        return;
    std::deque<std::pair<int, int> > pair;
    std::deque<int> winners;

    bool odd = (vec.size() % 2 != 0);
    int straggler = -1;
    if (odd)
        straggler = vec[vec.size() - 1];
    for (size_t i = 0; i < vec.size() / 2; ++i)
    {
        int a = vec[i * 2];
        int b = vec[(i * 2) +1];
        if (a < b)
            std::swap(a, b);
        pair.push_back(std::make_pair(a, b));
        winners.push_back(a);
    }
    mergeInsertSortDeque(winners);
    std::deque<int> MainChain;
    std::deque<int> Losers;
    for (size_t i = 0; i < winners.size(); ++i)
    {
        MainChain.push_back(winners[i]);
        for (size_t j = 0; j < pair.size(); ++j)
        {
            if (pair[j].first == winners[i]) {
                Losers.push_back(pair[j].second);
                break;
            }
        }
    }
    if (!Losers.empty())
        MainChain.insert(MainChain.begin(), Losers[0]);
    std::vector<int> InsertOrder = buildInsertOrder(Losers.size());
    if (odd) {
        Losers.push_back(straggler);
        InsertOrder.push_back(Losers.size() - 1);
    }
    for (size_t i = 0; i < InsertOrder.size(); ++i)
    {
        int index = InsertOrder[i];
        int value = Losers[index];
        std::deque<int>::iterator it = std::lower_bound(MainChain.begin(), MainChain.end(), value);
        MainChain.insert(it, value);
    }
    vec = MainChain;
}

PmergeMe::PmergeMe(char** argv)
{
    for (int i = 1; argv[i]; i++)
    {
        int num = std::atoi(argv[i]);
        if (num <= 0)
            throw InvalidArg();
        _vector.push_back(num);
        _deque.push_back(num);
    }
    printBefore();
    clock_t start = clock();
    mergeInsertSortVector(_vector);
    clock_t end = clock();
    _vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    start = clock();
    mergeInsertSortDeque(_deque);
    end = clock();
    _dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    print();
}