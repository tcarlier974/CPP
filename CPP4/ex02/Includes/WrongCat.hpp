#ifndef WRONGCAT_H
# define WRONGCAT_H
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &copy);
		virtual ~WrongCat();

		virtual void makeSound(void)const;
};

#endif