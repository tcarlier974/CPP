#ifndef AAnimal_H
# define AAnimal_H

# include <iostream>
typedef std::string str;

class AAnimal {
	protected :
		str type;
	public :
		AAnimal();
		AAnimal(const str& type);
		AAnimal(const AAnimal &copy);
		AAnimal &operator=(const AAnimal &src);
		virtual ~AAnimal();
		virtual void makeSound(void)const = 0;
		void setType(const str& type);
		str getType()const;
};

#endif