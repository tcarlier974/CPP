#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap 
{

	public :
		FragTrap();
		FragTrap(const FragTrap &copy);
		FragTrap(str name);
		~FragTrap();

		void attack(str target);
		void highFivesGuys(void);;
};

#endif