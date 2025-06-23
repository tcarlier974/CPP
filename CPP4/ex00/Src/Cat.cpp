#include "../Includes/Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	std::cout << "Default constructor called for Cat" << std::endl;
}

Cat::Cat(const Cat &copy){
	this->type = copy.type;
	std::cout << "Copy constructor called for Cat" << std::endl;
}

Cat::~Cat(){
	std::cout << "Destructor called for Cat" << std::endl;
}

void Cat::makeSound()const{
		std::cout << "\t*Meeeoow*\n";
}