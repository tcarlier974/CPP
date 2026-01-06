#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

typedef std::string str;
class ClapTrap {
	protected :
		str name;
		unsigned int hit;
		unsigned int energy;
		unsigned int attackDamage;

	public :
		ClapTrap();
		ClapTrap(str name);
		ClapTrap(const ClapTrap& original);
		ClapTrap &operator=(const ClapTrap& src);
		~ClapTrap();

		void attack(const str& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif