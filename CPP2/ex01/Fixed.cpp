#include "Fixed.hpp"


const int Fixed::bits = 8;

Fixed::Fixed(){
	this->fixed = 0;
	std::cout << "Fixed Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& original){
	std::cout << "Fixed Copy Constructor called" << std::endl;
	*this = original;
}

Fixed::~Fixed(){
	std::cout << "Fixed Deconstructor called" << std::endl;
}

int Fixed::getRawBits( void )const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixed;
}

void Fixed::setRawBits( int const value) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed = value;
}

Fixed &Fixed::operator=(const Fixed& src){
	std::cout << "Fixed Assignation operator called" << std::endl;
	if (&src != this)
	{
			this->fixed = src.getRawBits();
	}
	return *this;
}

Fixed::Fixed(const int i){
	std::cout << "Int constructor called" << std::endl;
	this->fixed = i << this->bits;
}

Fixed::Fixed(const float f){
	std::cout << "Float constructor called" << std::endl;
	this->fixed = roundf(f * (1 << this->bits));
}

int Fixed::toInt(void)const{
	return(this->fixed >> this->bits);
}

float Fixed::toFloat(void )const{
	return((float)this->fixed / (float)(1 << this->bits));
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}