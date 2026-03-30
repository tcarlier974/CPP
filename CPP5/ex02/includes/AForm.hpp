/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:38:43 by tcarlier          #+#    #+#             */
/*   Updated: 2026/03/30 17:10:37 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class AForm
{
	private:
		std::string const   _name;
		bool                _isSigned;
		int const           _gradeToSign;
		int const           _gradeToExec;

	public:
		AForm(std::string const & name, int gts, int gte);
		AForm(AForm const & src);
		virtual ~AForm();

		AForm &operator=(AForm const & src);
		std::string const & getName() const;
		bool isSigned() const;
		int getgts() const;
		int getgte() const;
		void beSigned(Bureaucrat const & src);
		virtual void execute(Bureaucrat const & executor) const = 0;

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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class ExecutorGradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & o, AForm const & src);

#endif