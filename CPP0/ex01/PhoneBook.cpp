#include "header.hpp"

PhoneBook::PhoneBook() : current(0), nb_contacts(0){

	std::cout << "PhoneBook generated successfully" << std::endl;
}

PhoneBook::~PhoneBook(){

	std::cout << "PhoneBook destroyed successfully" << std::endl;
}

void	PhoneBook::search(void){
	int	i = 0;
	str	name;
	str	last;
	str	nick;
	str	phone;
	str	secret;
	str	ret;
	int	index;
	
	if (this->current == 0) {
		std::cout << "0 contact in the phonebook, please add 1 before" << std::endl;
		return;
	}
	std::cout << "Index" << "|";
	std::cout << "Firstname" << "|";
	std::cout << " Lastname" << "|";
	std::cout << "Nickname" << std::endl;
	while (i < nb_contacts) {
		std::cout << i << "|";
		name = this->list[i].get_first();
		last = this->list[i].get_last();
		nick = this->list[i].get_nickname();
		phone = this->list[i].get_phone();
		secret = this->list[i].get_secret();
		if (name.length() > 9)
			name = name.substr(0, 9) + ".";
		if (last.length() > 9)
			last = last.substr(0, 9) + ".";
		if (nick.length() > 9)
			nick = nick.substr(0, 9) + ".";
		std::cout << name << "|";
		std::cout << last << "|";
		std::cout << nick << std::endl;
		i++;
	}
	std::cout << std::endl << "Type a contact's index to obtain personal informations : ";
	std::cin >> ret;
	index = atoi(ret.c_str());
	if ((index == 0 && ret[0] != '0') || (index > 7 || index < 0)) {
		std::cout << "Please enter a valid digit ! Abort..." << std::endl; return;
	}
	if (index >= this->nb_contacts) {
		std::cout << "No contact found ! Abort..." << std::endl; return;
	}
	std::cout << "Name : " << this->list[index].get_first() << std::endl;
	std::cout << "Lastname : " << this->list[index].get_last() << std::endl;
	std::cout << "Nickname : " << this->list[index].get_nickname() << std::endl;
	std::cout << "Phone number : " << this->list[index].get_phone() << std::endl;
	std::cout << "Darkest secret : " << this->list[index].get_secret() << std::endl;
}

void	PhoneBook::add(void){
	str	last;
	str	first;
	str nickname;
	str secret;
	str phone;

	if (this->current == 8)
		current = 0;
	std::cout << "first name :";
	std::cin >> first;
	std::cout << "last name :";
	std::cin >> last;
	std::cout << "nickname :";
	std::cin >> nickname;
	std::cout << "secret :";
	std::cin >> secret;
	std::cout << "phone number :";
	std::cin >> phone;
	this->list[this->current].set_first(first);
	this->list[this->current].set_last(last);
	this->list[this->current].set_nickname(nickname);
	this->list[this->current].set_secret(secret);
	this->list[this->current].set_phone(phone);
	std::cout << "Contact added successfully" << std::endl;
	this->current += 1;
	if (nb_contacts < 8)
		nb_contacts++;
}