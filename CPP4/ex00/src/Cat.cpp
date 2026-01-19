#include "../Includes/Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Default constructor called for Cat" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	std::cout << "Copy constructor called for Cat" << std::endl;
}

Cat::~Cat(){
	std::cout << "Destructor called for Cat" << std::endl;
}

Cat &Cat::operator=(const Cat &src){
	std::cout << "Cat Assignation operator called" << std::endl;
	if (this != &src)
		this->type = src.type;
	return *this;
}

void Cat::makeSound()const{
		std::cout << "\t*Meeeoow*\n";
}