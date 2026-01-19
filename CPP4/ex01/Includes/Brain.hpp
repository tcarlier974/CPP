#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>
typedef std::string str;

class Brain {
	private:
		str ideas[100];
		Brain( str );
	public :
		Brain();
		Brain(const Brain &copy);
		~Brain();
		Brain &operator=(const Brain &src);

		// const str getIdea(size_t i)const;
		// void setIdea(size_t i, str idea);
		// const str *getIdeaAddress(size_t i)const;
};

#endif