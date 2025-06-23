#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>
typedef std::string str;

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		virtual ~WrongAnimal();

		virtual void makeSound(void)const;
		str getType()const;
};

#endif