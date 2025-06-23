#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain* dogBrain;
	public:
		Dog();
		Dog(const Dog &copy);
		virtual ~Dog();
		Dog &operator=(const Dog &src);

		virtual void makeSound()const;
		void getIdeas(void)const;
		void setIdea(size_t i, str idea);
};

#endif