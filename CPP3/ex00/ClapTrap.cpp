#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	this->attackDamage = 0;
	this->energy = 10;
	this->name = "someone we don't need to call";
	this->hit = 10;
	std::cout << "New unnamed ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(str name){
	this->name = name;
	this->attackDamage = 0;
	this->energy = 10;
	this->hit = 10;
	std::cout << "The new ClapTrap " << name << " is build" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& original){
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = original;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& src){
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	if (&src != this)
	{
			this->name = src.name;
			this->hit = src.hit;
			this->energy = src.energy;
			this->attackDamage = src.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << this->name << " is destroyed" << std::endl;
}

void ClapTrap::attack(const str& target){
	if (this->energy > 0 && this->hit > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energy--;
	}
	else if (this->energy == 0)
		std::cout << "ClapTrap " << this->name << " is not able to attack " << target << ", because he has no energy points left." << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " is not able to attack " << target << ", because he has not enough hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->energy >= 1 && this->hit > 0){
		this->hit += amount;
		this->energy--;
		std::cout << "The ClapTrap " << this->name << "repaired himself and his now at " << this->hit << " hit points\n"; 
	}
	else if (this->energy == 0)
		std::cout << "ClapTrap " << this->name << " is not able to repair itself, because he doesn't have enough energy points." << std::endl;
	else if (this->hit == 0)
		std::cout << "ClapTrap " << this->name << " is not able to repair itself, because he doesn't have enough hit points." << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " can't be repaired to have more than 10 hit points." << std::endl;	
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->hit > amount)
		this->hit -= amount;
	else if (this->hit > 0)
		this->hit = 0;
	else
	{
		std::cout << "ClapTrap " << this->name << " is already dead, stop beating it." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " was attacked and lost " << amount << " hit points, he now has " << this->hit << " hit points." << std::endl;
}