#include "Zombie.hpp"

int	main() {
	Zombie* z = NULL;

	z = newZombie("Ivan");
	z->announce();
	randomChump("SAM");
	delete z;
}