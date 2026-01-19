#ifndef DOG_H
# define DOG_H

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
	private:
		Brain* brain;
	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();
		Dog &operator=(const Dog &src);

		void makeSound()const;
		// void getIdeas(void)const;
		// void setIdea(size_t i, str idea);
};

#endif