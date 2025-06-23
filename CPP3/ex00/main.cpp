#include "ClapTrap.hpp"

int main(void) {
	{
		ClapTrap a;
		ClapTrap b("Beeeeeee");

		a.attack("Beeeeee");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("the cousin of Beeeeee");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("Beeeee's family member");
		b.beRepaired(3);
	}
	return (0);
}