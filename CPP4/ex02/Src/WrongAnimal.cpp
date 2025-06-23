#include "../Includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	this->type = "WrongAnimal but not specific";
	std::cout << "Default constructor called for WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy){
	this->type = copy.type;
	std::cout << "Copy constructor called for WrongAnimal" << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "Destructor called for WrongAnimal" << std::endl;
}

void WrongAnimal::makeSound()const{
	std::cout << "This animal doesn't make any sound. or maybe a burp" << std::endl;
}

str WrongAnimal::getType()const {
	return (this->type);
}