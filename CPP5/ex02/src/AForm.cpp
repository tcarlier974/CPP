/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:51:47 by tcarlier          #+#    #+#             */
/*   Updated: 2026/03/30 16:32:27 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm(std::string const & name, int gts, int gte) : _name(name), _isSigned(false), _gradeToSign(gts), _gradeToExec(gte)
{
    if (gts < 1 || gte < 1)
        throw AForm::GradeTooHighException();
    if (gts > 150 || gte > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(AForm const & src)
{
    if (this != &src)
        this->_isSigned = src._isSigned;
    return *this;
}

std::string const & AForm::getName() const
{
    return this->_name;
}

bool AForm::isSigned() const
{
    return this->_isSigned;
}

int AForm::getgts() const
{
    return this->_gradeToSign;
}

int AForm::getgte() const
{
    return this->_gradeToExec;
}

void AForm::beSigned(Bureaucrat const & src)
{
    if (src.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    else if (this->_isSigned)
        throw "Form is already signed";
    this->_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

const char* AForm::ExecutorGradeTooLowException::what() const throw()
{
    return "Executor grade is too low";
}

std::ostream & operator<<(std::ostream & o, AForm const & src)
{
    o << "Form " << src.getName() << " is " << (src.isSigned() ? "signed" : "not signed") << ", grade to sign: " << src.getgts() << ", grade to execute: " << src.getgte();
    return o;
}
