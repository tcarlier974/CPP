#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain* catBrain;
	public:
		Cat();
		Cat(const Cat &copy);
		virtual ~Cat();
		Cat &operator=(const Cat &src);

		virtual void makeSound()const;
		void getIdeas(void)const;
		void setIdea(size_t i, str idea);
};

#endif