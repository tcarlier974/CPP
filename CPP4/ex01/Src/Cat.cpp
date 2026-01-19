#include "../Includes/Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	this->catBrain = new Brain();
	std::cout << "Default constructor called for Cat" << std::endl;
	if (this->catBrain == NULL)
	{
		perror("Cat Brain allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
}

Cat::Cat(const Cat &copy){
	this->type = copy.type;
	this->catBrain = new Brain(*copy.catBrain);
	std::cout << "Copy constructor called for Cat" << std::endl;
	if (this->catBrain == NULL)
	{
		perror("Cat Brain allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
}

Cat::~Cat(){
	delete this->catBrain;
	std::cout << "Destructor called for Cat" << std::endl;
}

void Cat::makeSound()const{
		std::cout << "\t*Meeeoow*\n";
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	this->type = src.type;
	delete this->catBrain;
	this->catBrain = new Brain(*src.catBrain);
	if (this->catBrain == NULL)
	{
		perror("Cat Brain allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
	return *this;
}

void	Cat::getIdeas(void)const
{
	for (int i = 0; i < 3; i++)// change the 3 to 100 to show all ideas
		std::cout << "\tIdea " << i << " of the Cat is: \"" << this->catBrain->getIdea(i) << "\" at the address " << this->catBrain->getIdeaAddress(i) << std::endl;
}

void	Cat::setIdea(size_t i, std::string idea)
{
		this->catBrain->setIdea(i, idea);
}