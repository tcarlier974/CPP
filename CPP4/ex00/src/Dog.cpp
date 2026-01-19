#include "../Includes/Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Default constructor called for Dog" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	std::cout << "Copy constructor called for Dog" << std::endl;
}

Dog::~Dog(){
	std::cout << "Destructor called for Dog" << std::endl;
}

Dog &Dog::operator=(const Dog &src){
	std::cout << "Dog Assignation operator called" << std::endl;
	if (this != &src)
		this->type = src.type;
	return *this;
}

void Dog::makeSound()const{
		std::cout << "\t*WOAF WOAF*\n";
}