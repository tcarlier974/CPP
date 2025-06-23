#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>
typedef std::string str;

class Animal {
	protected :
		str type;
	public :
		Animal();
		Animal(const Animal &copy);
		virtual ~Animal();
		virtual void makeSound(void)const;
		str getType()const;
};

#endif