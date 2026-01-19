#include "../Includes/AAnimal.hpp"

AAnimal::AAnimal(){
	this->type = "AAnimal but not specific";
	std::cout << "Default constructor called for AAnimal" << std::endl;
}

AAnimal::AAnimal(const str& type) : type(type){
	std::cout << "Here comes the... The AAnimal of type " << type << " !\n";
}

AAnimal::AAnimal(const AAnimal &copy){
	this->type = copy.type;
	std::cout << "Copy constructor called for AAnimal" << std::endl;
}

AAnimal::~AAnimal(){
	std::cout << "Destructor called for AAnimal" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &src){
	std::cout << "AAnimal Assignation operator called" << std::endl;
	if (this != &src)
		this->type = src.type;
	return *this;
}

void AAnimal::makeSound()const{
	std::cout << "This AAnimal doesn't make any sound." << std::endl;
}

str AAnimal::getType()const{
	return (this->type);
}

void AAnimal::setType(const str& type) {
	this->type = type;
}
