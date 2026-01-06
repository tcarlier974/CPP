#include "replace.hpp"


str replace(str current, str str1, str str2){
	size_t i = current.find(str1);
	
	while(i != std::string::npos){
			current.erase(i, str1.length());
			current.insert(i, str2);
			i = current.find(str1, i + str2.length());
	}
	return(current);
}

int main(int ac, char** av) {
	
	str current;
	
	if (ac != 4)
		return (std::cout <<"Usage : <filename> str1 str2" << std::endl, 1);
	str filename = av[1];
	str str1 = av[2];
	str str2 = av[3];
	if (str1.empty())
		return (std::cout << "Error: s1 cannot be empty" << std::endl, 1);
	std::ifstream ifs(av[1]);
	if (!ifs.is_open())
		return (std::cout << "Error: cannot open file" << std::endl, 1);
	std::ofstream ofs(filename + ".replace");
	if (!ofs.is_open())
		return (ifs.close(), std::cout << "Error: cannot create output file" << std::endl, 1);
	bool firstLine = true;
	while (std::getline(ifs, current)){
		if (!firstLine)
			ofs << "\n";
		current = replace(current, str1, str2);
		ofs << current;
		firstLine = false;
	}
	ifs.close();
	ofs.close();
	return 0;
}