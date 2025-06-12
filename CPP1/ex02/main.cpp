#include <iostream>
typedef std::string str;

int main(void){
	str *stringPTR;
	str brain = "HI THIS IS BRAIN";
	str& stringREF = brain;

	stringPTR = &brain;
	std::cout << &brain << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << brain << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}