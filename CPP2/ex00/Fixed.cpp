#include "Fixed.hpp"


const int Fixed::bits = 8;

Fixed::Fixed(){
	this->fixed = 0;
	std::cout << "Fixed Default Constructor called" << std::endl;
}

Fixed::Fixed(Fixed& original){
	std::cout << "Fixed Copy Constructor called" << std::endl;
	*this = original;
}

Fixed::~Fixed(){
	std::cout << "Fixed Deconstructor called" << std::endl;
}

int Fixed::getRawBits( void ){
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixed;
}

void Fixed::setRawBits( int const value) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed = value;
}

Fixed &Fixed::operator=(Fixed& src){
	std::cout << "Fixed Assignation operator called" << std::endl;
	if (&src != this)
	{
			this->fixed = src.getRawBits();
	}
	return *this;
}