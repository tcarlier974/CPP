#include "Zombie.hpp"

Zombie::Zombie(void) {
	std::cout << this->name << " woke up" << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->name << " died (again)" << std::endl;
}

void	Zombie::announce(){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(str name){
	this->name = name;
}