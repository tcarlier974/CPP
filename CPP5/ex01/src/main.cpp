/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:36:33 by tcarlier          #+#    #+#             */
/*   Updated: 2026/03/30 16:07:28 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main()
{
    try
    {
        std::cout << "\n=== Test 1: Form with grade 1, Bureaucrat grade 1 ===" << std::endl;
        Form a("a", 1, 1);
        std::cout << a << std::endl;
        Bureaucrat b("b", 1);
        b.signForm(a);
        std::cout << a << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    try
    {
        std::cout << "\n=== Test 2: Form with grade 150, Bureaucrat grade 150 ===" << std::endl;
        Form c("c", 150, 150);
        std::cout << c << std::endl;
        Bureaucrat d("d", 150);
        d.signForm(c);
        std::cout << c << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    try
    {
        std::cout << "\n=== Test 3: Form with invalid grade 0 ===" << std::endl;
        Form e("e", 0, 0);
        std::cout << e << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    try
    {
        std::cout << "\n=== Test 4: Form with invalid grade 151 ===" << std::endl;
        Form f("f", 151, 151);
        std::cout << f << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    try
    {
        std::cout << "\n=== Test 5: Bureaucrat too low to sign ===" << std::endl;
        Form g("g", 1, 1);
        std::cout << g << std::endl;
        Bureaucrat h("h", 150);
        h.signForm(g);
        std::cout << g << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    try
    {
        std::cout << "\n=== Test 6: Sign same form twice ===" << std::endl;
        Form i("i", 1, 1);
        std::cout << i << std::endl;
        Bureaucrat j("j", 1);
        j.signForm(i);
        j.signForm(i);
        std::cout << i << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}