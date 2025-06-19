#include "Fixed.hpp"


const int Fixed::bits = 8;

Fixed::Fixed(){
	this->fixed = 0;
}

Fixed::Fixed(const Fixed& original){
	*this = original;
}

Fixed::~Fixed(){
}

int Fixed::getRawBits( void )const{
	return this->fixed;
}

void Fixed::setRawBits( int const value) {
	this->fixed = value;
}

Fixed &Fixed::operator=(const Fixed& src){
	if (&src != this)
	{
			this->fixed = src.getRawBits();
	}
	return *this;
}

Fixed::Fixed(const int i){
	this->fixed = i << this->bits;
}

Fixed::Fixed(const float f){
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

Fixed Fixed::operator>(Fixed src){
	return (this->toFloat() > src.toFloat());
}

Fixed Fixed::operator>=(Fixed src){
	return (this->toFloat() >= src.toFloat());
}

Fixed Fixed::operator<(Fixed src){
	return (this->toFloat() < src.toFloat());
}

Fixed Fixed::operator<=(Fixed src){
	return (this->toFloat() <= src.toFloat());
}

Fixed Fixed::operator==(Fixed src){
	return (this->toFloat() == src.toFloat());
}

Fixed Fixed::operator!=(Fixed src){
	return (this->toFloat() != src.toFloat());
}

Fixed Fixed::operator+(Fixed src){
	return (this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(Fixed src){
	return (this->toFloat() - src.toFloat());
}

Fixed Fixed::operator/(Fixed src){
	return (this->toFloat() / src.toFloat());
}

Fixed Fixed::operator*(Fixed src){
	return (this->toFloat() * src.toFloat());
}

Fixed &Fixed::operator++(){
	++this->fixed;
	return *this;
}

Fixed Fixed::operator++(int ){
	Fixed tmp = *this;
	this->fixed++;
	return (tmp);
}

Fixed &Fixed::operator--(){
	--this->fixed;
	return (*this);
}

Fixed Fixed::operator--(int ){
	Fixed tmp = *this;
	this->fixed--;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &first, Fixed &second){
	if (first.toFloat() < second.toFloat())
		return first;
	else
		return second;
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second){
	if (first.toFloat() < second.toFloat())
		return first;
	else
		return second;
}

Fixed	&Fixed::max(Fixed &first, Fixed &second){
	if (first.toFloat() > second.toFloat())
		return first;
	else
		return second;
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second){
	if (first.toFloat() > second.toFloat())
		return first;
	else
		return second;
}