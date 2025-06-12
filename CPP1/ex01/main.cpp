#include "Zombie.hpp"

int main(void){
	Zombie* horde = NULL;

	horde = zombieHorde(3, "Hector");
	delete[] horde;
}