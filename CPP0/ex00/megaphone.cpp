#include <iostream>


void	megaphone(std::string mystring)
{
	std::string result = mystring;
	std::transform(result.begin(), result.end(), result.begin(), ::toupper);
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