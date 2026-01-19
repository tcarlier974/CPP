#include "../Includes/Dog.hpp"

Dog::Dog() : AAnimal("Dog"), brain(new Brain) {
	std::cout << "Here comes the Dog !\n";
}

Dog::Dog(const Dog &other) : AAnimal(other), brain(new Brain(*other.brain)) {
	std::cout << "Here comes the Dog !\n";
}

Dog::~Dog(){
	std::cout << "The Dog is gone...\n";
	delete brain;
}

void Dog::makeSound()const{
		std::cout << "\t*WOAF WOAF*\n";
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		AAnimal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

// void	Dog::getIdeas(void)const
// {
// 	for (int i = 0; i < 3; i++)// change the 3 to 100 to show all ideas
// 		std::cout << "\tIdea " << i << " of the Cat is: \"" << this->brain->getIdea(i) << "\" at the address " << this->brain->getIdeaAddress(i) << std::endl;
// }

// void	Dog::setIdea(size_t i, std::string idea)
// {
// 		this->brain->setIdea(i, idea);
// }