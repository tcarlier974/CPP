#include "../Includes/Brain.hpp"

Brain::Brain(){
	std::cout << "Default constructor called for Brain" << std::endl;
}

Brain::Brain(const Brain &copy){
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain(){
	std::cout << "Destructor called for Brain" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Brain Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = src.ideas[i];
	}
	return *this;
}

// const str	Brain::getIdea(size_t i)const
// {
// 	if (i < 100)
// 		return(this->ideas[i]);
// 	else
// 		return ("\033[33mThere is only 100 ideas per brain.\033[0m");
// }

// const str *Brain::getIdeaAddress(size_t i)const
// {
// 	if (i < 100)
// 	{
// 		const str	&stringREF = this->ideas[i];
// 		return(&stringREF);
// 	}
// 	else
// 		return (NULL);
// }

// void	Brain::setIdea(size_t i, str idea)
// {
// 	if (i < 100)
// 		this->ideas[i] = idea;
// 	else
// 		std::cout << "\033[33mThere is only 100 ideas per brain.\033[0m" << std::endl;
// }