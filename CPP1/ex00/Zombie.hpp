
#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>
# include "Zombie.hpp"

typedef std::string str;



class Zombie {
	private :
		str name;

	public :
		Zombie( str name );
		~Zombie(void);
		void	announce();
};

Zombie* newZombie(str name);
void randomChump(str name);

#endif