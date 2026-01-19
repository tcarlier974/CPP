#include "../Includes/Animal.hpp"

Animal::Animal(){
	this->type = "Animal but not specific";
	std::cout << "Default constructor called for Animal" << std::endl;
}

Animal::Animal(const str& type) : type(type){
	std::cout << "Here comes the... The Animal of type " << type << " !\n";
}

Animal::Animal(const Animal &copy){
	this->type = copy.type;
	std::cout << "Copy constructor called for Animal" << std::endl;
}

Animal::~Animal(){
	std::cout << "Destructor called for Animal" << std::endl;
}

Animal &Animal::operator=(const Animal &src){
	std::cout << "Animal Assignation operator called" << std::endl;
	if (this != &src)
		this->type = src.type;
	return *this;
}

void Animal::makeSound()const{
	std::cout << "This animal doesn't make any sound." << std::endl;
}

str Animal::getType()const{
	return (this->type);
}

void Animal::setType(const str& type) {
	this->type = type;
}
