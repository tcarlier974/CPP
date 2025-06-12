#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "header.hpp"

class PhoneBook{
	public :

		PhoneBook(void);
		~PhoneBook(void);

		void	search(void);
		void	add(void);

	private :
		int current;
		int nb_contacts;
		Contact list[8];
};
 #endif