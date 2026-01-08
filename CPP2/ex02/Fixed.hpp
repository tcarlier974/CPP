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
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		Fixed &operator++();
		Fixed operator++(int i);
		Fixed &operator--();
		Fixed operator--(int i);

		
		~Fixed();
		int getRawBits( void )const;
		void setRawBits( int const value );

		int toInt(void)const;
		float toFloat(void)const ;
		static Fixed& min(Fixed &f1, Fixed &f2);
		static const Fixed &min(const Fixed &f1, const Fixed &f2);
		static Fixed &max( Fixed &f1, Fixed &f2);
		static const Fixed &max(const Fixed &f1, const Fixed &f2);
		
	private:
		int fixed;
		static int const bits;
		
	};

std::ostream &operator<<(std::ostream &op, Fixed const &fixed);
	
	#endif