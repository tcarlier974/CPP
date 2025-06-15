#ifndef FIXED_H
# define FIXED_H

#include <iostream>

typedef std::string str;

class Fixed{
	public :
		Fixed();
		Fixed(Fixed& original);
		Fixed &operator=(Fixed& src);

		~Fixed();
		int getRawBits( void );
		void setRawBits( int const value );
	private:
		int fixed;
		static int const bits;
		
};

#endif