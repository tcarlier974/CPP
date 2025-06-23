#include "../Includes/Dog.hpp"

Dog::Dog(){
	this->type = "Dog";
	this->dogBrain = new Brain();
	std::cout << "Default constructor called for Dog" << std::endl;
	if (this->dogBrain == NULL)
	{
		perror("Dog Brain alloDogion failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
}

Dog::Dog(const Dog &copy){
	*this = copy;
	std::cout << "Copy constructor called for Dog" << std::endl;
}

Dog::~Dog(){
	delete this->dogBrain;
	std::cout << "Destructor called for Dog" << std::endl;
}

void Dog::makeSound()const{
		std::cout << "\t*WOAF WOAF*\n";
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	this->type = src.type;
	this->dogBrain = new Brain();
	if (this->dogBrain == NULL)
	{
		perror("Dog Brain alloDogion failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
	*this->dogBrain = *src.dogBrain;
	return *this;
}

void	Dog::getIdeas(void)const
{
	for (int i = 0; i < 3; i++)// change the 3 to 100 to show all ideas
		std::cout << "\tIdea " << i << " of the Cat is: \"" << this->dogBrain->getIdea(i) << "\" at the address " << this->dogBrain->getIdeaAddress(i) << std::endl;
}

void	Dog::setIdea(size_t i, std::string idea)
{
		this->dogBrain->setIdea(i, idea);
}