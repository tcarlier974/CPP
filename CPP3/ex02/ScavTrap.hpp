#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
	private :
		bool guard;

	public :
		ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap(str name);
		~ScavTrap();

		void attack(str target);
		void guardGate();
};

#endif