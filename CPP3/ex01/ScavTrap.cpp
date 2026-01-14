#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->attackDamage = 20;
	this->energy = 50;
	this->guard = false;
	this->hit = 100;
	std::cout << "Default constructor ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	this->guard = copy.guard;
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src){
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	if (&src != this)
	{
			this->name = src.name;
			this->hit = src.hit;
			this->energy = src.energy;
			this->attackDamage = src.attackDamage;
			this->guard = src.guard;
	}
	return *this;
}

ScavTrap::ScavTrap(str name): ClapTrap(name)
{
	this->attackDamage = 20;
	this->energy = 50;
	this->guard = false;
	this->hit = 100;
	std::cout << this->name << " constructor ScavTrap called" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap Deconstructor for " << this->name << " called" << std::endl;
}

void ScavTrap::attack(str target)
{
	if (this->energy > 0 && this->hit > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energy--;
	}
	else if (this->energy == 0)
		std::cout << "ScavTrap " << this->name << " is not able to attack " << target << ", because he has no energy points left." << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " is not able to attack " << target << ", because he has not enough hit points." << std::endl;
}

void ScavTrap::guardGate(){
	if (this->guard)
		this->guard = false;
	else
	{
		std::cout << "ScavTrap" << this->name << "is now in Gate keeper mode" << std::endl;
		this->guard = true;
	}
}