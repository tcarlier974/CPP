#ifndef FIXED_H
# define FIXED_H

#include <iostream>

typedef std::string str;

class Fixed{
	public :
		Fixed();
		Fixed(const Fixed& original);
		Fixed &operator=(const Fixed& src);

		~Fixed();
		int getRawBits( void ) const ;
		void setRawBits( int const value );
	private:
		int fixed;
		static int const bits;
		
};

#endif