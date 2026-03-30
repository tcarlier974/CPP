/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:38:43 by tcarlier          #+#    #+#             */
/*   Updated: 2026/03/30 15:40:15 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

class Form
{
    private:
        std::string const   _name;
        bool                _isSigned;
        int const           _gradeToSign;
        int const           _gradeToExec;

    public:
        Form(std::string const & name, int gts, int gte);
        Form(Form const & src);
        ~Form();

        Form &operator=(Form const & src);
        std::string const & getName() const;
        bool isSigned() const;
        int getgts() const;
        int getgte() const;
        void beSigned(Bureaucrat const & src);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};