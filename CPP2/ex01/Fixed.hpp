#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

typedef std::string str;

class Fixed{
	public :
		Fixed();
		Fixed(const Fixed& original);
		Fixed(int const i);
		Fixed(float const f);
		
		Fixed &operator=(const Fixed& src);

		
		~Fixed();
		int getRawBits( void )const;
		void setRawBits( int const value );
		int toInt(void)const;
		float toFloat(void)const ;
		
	private:
		int fixed;
		static int const bits;
		
	};

std::ostream &operator<<(std::ostream &op, Fixed const &fixed);
	
	#endif