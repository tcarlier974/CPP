#include "../Includes/WrongCat.hpp"

WrongCat::WrongCat(){
	this->type = "WrongCat";
	std::cout << "Default constructor called for WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy){
	this->type = copy.type;
	std::cout << "Copy constructor called for WrongCat" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "Destructor called for WrongCat" << std::endl;
}

void WrongCat::makeSound()const{
		std::cout << "\t*MEEEEEEEUUUUUUH*\n";
}