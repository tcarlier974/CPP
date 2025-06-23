#include "../Includes/Dog.hpp"

Dog::Dog(){
	this->type = "Dog";
	std::cout << "Default constructor called for Dog" << std::endl;
}

Dog::Dog(const Dog &copy){
	this->type = copy.type;
	std::cout << "Copy constructor called for Dog" << std::endl;
}

Dog::~Dog(){
	std::cout << "Destructor called for Dog" << std::endl;
}

void Dog::makeSound()const{
		std::cout << "\t*WOAF WOAF*\n";
}