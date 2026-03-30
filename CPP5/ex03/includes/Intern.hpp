/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:46:38 by tcarlier          #+#    #+#             */
/*   Updated: 2026/03/30 17:03:33 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
#include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(Intern const & src);
        ~Intern();

        Intern &operator=(Intern const & src);
        AForm *makeForm(std::string const & name, std::string const & target) const;

        class FormNotFoundException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif