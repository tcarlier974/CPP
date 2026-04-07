#include "../Includes/Cat.hpp"

Cat::Cat() : AAnimal("Cat"), brain(new Brain()) {
	std::cout << "Here comes the Cat !\n";
}

Cat::Cat(const Cat &other) : AAnimal(other), brain(new Brain(*other.brain)) {
	std::cout << "Here comes the Cat !\n";
}

Cat::~Cat(){
	std::cout << "The Cat is gone...\n";
	delete brain;
}

void Cat::makeSound()const{
		std::cout << "\t*Meeeoow*\n";
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		AAnimal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

// void	Cat::getIdeas(void)const
// {
// 	for (int i = 0; i < 3; i++)// change the 3 to 100 to show all ideas
// 		std::cout << "\tIdea " << i << " of the Cat is: \"" << this->brain->getIdea(i) << "\" at the address " << this->brain->getIdeaAddress(i) << std::endl;
// }

// void	Cat::setIdea(size_t i, std::string idea)
// {
// 		this->brain->setIdea(i, idea);
// }