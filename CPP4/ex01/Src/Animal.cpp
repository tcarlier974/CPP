#include "../Includes/Animal.hpp"

Animal::Animal(){
	this->type = "Animal but not specific";
	std::cout << "Default constructor called for Animal" << std::endl;
}

Animal::Animal(const Animal &copy){
	this->type = copy.type;
	std::cout << "Copy constructor called for Animal" << std::endl;
}

Animal::~Animal(){
	std::cout << "Destructor called for Animal" << std::endl;
}

void Animal::makeSound()const{
	std::cout << "This animal doesn't make any sound." << std::endl;
}

str Animal::getType()const{
	return (this->type);
}