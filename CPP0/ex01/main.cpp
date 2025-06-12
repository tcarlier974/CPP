#include "header.hpp"

int main(void)
{
	str commande;
	PhoneBook	phone_book;
	while (1) {
		std::cout << "Type SEARCH, ADD or EXIT..." << std::endl;
		std::cin >> commande;
		if (!commande.compare("EXIT")){
			break ;
		}
		else if (!commande.compare("ADD")){
			phone_book.add();
		}
		else if (!commande.compare("SEARCH")){
			phone_book.search();
		}
	}
	return (0);
}