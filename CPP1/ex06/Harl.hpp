#ifndef HARL_H
# define HARL_H

# include <iostream>

typedef std::string str;

class Harl{
	public :
		Harl( void );
		~Harl( void );
		void complain( str level );

	private :
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif