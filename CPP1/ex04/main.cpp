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
	std::ifstream ifs;
	std::ofstream ofs(filename + ".replace");
	ifs.open(av[1]);
	if (ifs.is_open() == true){
		while (std::getline(ifs, current)){
			current = replace(current, str1, str2);
			ofs << current;
			if (ifs.peek() == '\n')
				ofs << std::endl;
		}
	}
	ifs.close();
	ofs.close();
	return 0;
}