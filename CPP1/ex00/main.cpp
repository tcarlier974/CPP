#include "Zombie.hpp"

int	main() {
	Zombie* z = NULL;

	z = z->newZombie("Ivan");
	z->announce();
	z->randomChump("SAM");
	delete z;
}