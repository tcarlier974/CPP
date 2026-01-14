#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->attackDamage = 30;
	this->energy = 100;
	this->hit = 100;
	std::cout << "Default constructor FragTrap called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap::FragTrap(str name): ClapTrap(name)
{
	this->attackDamage = 30;
	this->energy = 100;
	this->hit = 100;
	std::cout << this->name << " constructor FragTrap called" << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap Deconstructor for " << this->name << " called" << std::endl;
}

void FragTrap::attack(str target)
{
	if (this->energy > 0 && this->hit > 0)
	{
		std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energy--;
	}
	else if (this->energy == 0)
		std::cout << "FragTrap " << this->name << " is not able to attack " << target << ", because he has no energy points left." << std::endl;
	else
		std::cout << "FragTrap " << this->name << " is not able to attack " << target << ", because he has not enough hit points." << std::endl;
}

void FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << this->name << ": You want a high five?\n\t*WHAMM*\nHere you go." << std::endl;
}