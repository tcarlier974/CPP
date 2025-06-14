#include <iostream>


void	megaphone(std::string mystring)
{
	std::string result = mystring;
	for(int i = 0; i < (int)result.length(); i++){
		if (result[i] >= 'a' && result[i] <= 'z')
			result[i] -= 32;
	}
	std::cout << result;
}

int main(int ac, char** av) {
	if (!av[1])
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<< std::endl;
	else
	{
		for (int i = 1; i < ac; i++) {
			megaphone(av[i]);
			if (av[i + 1])
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}