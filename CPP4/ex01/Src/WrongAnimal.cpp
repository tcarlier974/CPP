#include "../Includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	this->type = "WrongAnimal but not specific";
	std::cout << "Default constructor called for WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const str& type) : type(type) {
	std::cout << "Here comes the... The WrongAnimal of type " << type << " !\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy){
	this->type = copy.type;
	std::cout << "Copy constructor called for WrongAnimal" << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "Destructor called for WrongAnimal" << std::endl;
}

void WrongAnimal::makeSound() const {
	if (!type.empty()) {
		std::cout << "You hear a noise... You think it\'s a " << type << "\n";
	}
	else {
		std::cout << "You hear a noise but can't tell from which animal it is...\n";
	}
}

str WrongAnimal::getType()const {
	return (this->type);
}

void WrongAnimal::setType(const str& type) {
	this->type = type;
}