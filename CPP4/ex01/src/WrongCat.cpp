#include "../Includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "Default constructor called for WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
	std::cout << "Copy constructor called for WrongCat" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return (*this);
}

WrongCat::~WrongCat(){
	std::cout << "Destructor called for WrongCat" << std::endl;
}

void WrongCat::makeSound()const{
		std::cout << "\t*Meoooow*\n";
}