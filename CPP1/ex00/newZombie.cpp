#include "Zombie.hpp"

Zombie* Zombie::newZombie(str name){
	Zombie* zomb = new Zombie(name);
	return zomb;
}