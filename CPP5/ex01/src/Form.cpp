/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:51:47 by tcarlier          #+#    #+#             */
/*   Updated: 2026/03/30 15:58:45 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(std::string const & name, int gts, int gte) : _name(name), _isSigned(false), _gradeToSign(gts), _gradeToExec(gte)
{
    if (gts < 1 || gte < 1)
        throw Form::GradeTooHighException();
    if (gts > 150 || gte > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const & src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
}

Form::~Form()
{
}

Form &Form::operator=(Form const & src)
{
    if (this != &src)
        this->_isSigned = src._isSigned;
    return *this;
}

std::string const & Form::getName() const
{
    return this->_name;
}

bool Form::isSigned() const
{
    return this->_isSigned;
}

int Form::getgts() const
{
    return this->_gradeToSign;
}

int Form::getgte() const
{
    return this->_gradeToExec;
}

void Form::beSigned(Bureaucrat const & src)
{
    if (src.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    else if (this->_isSigned)
        throw "Form is already signed";
    this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream & operator<<(std::ostream & o, Form const & src)
{
    o << "Form " << src.getName() << " is " << (src.isSigned() ? "signed" : "not signed") << ", grade to sign: " << src.getgts() << ", grade to execute: " << src.getgte();
    return o;
}
