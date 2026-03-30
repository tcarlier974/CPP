/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:49:43 by tcarlier          #+#    #+#             */
/*   Updated: 2026/03/30 17:04:32 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationFrom.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const & src)
{
    (void)src;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(Intern const & src)
{
    (void)src;
    return *this;
}

AForm *makeShrubberyCreationForm(std::string const & target)
{
    return new ShrubberyCreationForm(target);
}

AForm *makeRobotomyRequestForm(std::string const & target)
{
    return new RobotomyRequestForm(target);
}

AForm *makePresidentialPardonForm(std::string const & target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const & name, std::string const & target) const
{
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(*formCreators[3])(std::string const &) = {
        makeShrubberyCreationForm,
        makeRobotomyRequestForm,
        makePresidentialPardonForm
    };

    for (int i = 0; i < 3; i++)
    {
        if (name == formNames[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return formCreators[i](target);
        }
    }
    throw Intern::FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return "Form not found";
}