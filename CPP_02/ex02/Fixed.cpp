#include "Fixed.hpp"

Fixed::Fixed() {
    fixedPointVal = 0;
}

Fixed::Fixed(const int n) {
    this->fixedPointVal = n << this->fractBits;
}

Fixed::Fixed(const float f) {
    this->fixedPointVal = roundf(f * (1 << fractBits));
}

Fixed::Fixed(const Fixed &original)
{
	*this = original;
}

Fixed &Fixed::operator = (const Fixed &original)
{
    if (this != &original)
    {
        this->fixedPointVal = original.getRawBits();
    }
    return *this;
}

Fixed::~Fixed(){}

int Fixed::getRawBits(void) const
{
    return this->fixedPointVal;
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPointVal = raw;
}
int Fixed::toInt(void) const
{
	return this->fixedPointVal >> this->fractBits;
}

float Fixed::toFloat(void) const
{
	return (float)this->fixedPointVal / (float)(1 << this->fractBits);
}

Fixed Fixed::operator+(const Fixed &otherobject) const
{
	return Fixed(this->toFloat() + otherobject.toFloat());
}

Fixed Fixed::operator-(const Fixed &otherobject) const
{
	return Fixed(this->toFloat() - otherobject.toFloat());
}

Fixed Fixed::operator*(const Fixed &otherobject) const
{
	return Fixed(this->toFloat() * otherobject.toFloat());
}

Fixed Fixed::operator/(const Fixed &otherobject) const
{
	return Fixed(this->toFloat() / otherobject.toFloat());
}

bool Fixed::operator>(const Fixed &otherobject) const
{
	return this->getRawBits() > otherobject.getRawBits();
}

bool Fixed::operator<(const Fixed &otherobject) const
{
	return this->getRawBits() < otherobject.getRawBits();
}

bool Fixed::operator>=(const Fixed &otherobject) const
{
	return this->getRawBits() >= otherobject.getRawBits();
}

bool Fixed::operator<=(const Fixed &otherobject) const
{
	return this->getRawBits() <= otherobject.getRawBits();
}

bool Fixed::operator==(const Fixed &otherobject) const
{
	return this->getRawBits() == otherobject.getRawBits();
}

bool Fixed::operator!=(const Fixed &otherobject) const
{
	return this->getRawBits() != otherobject.getRawBits();
}

Fixed &Fixed::operator++(void)
{
	this->fixedPointVal++;
	return *this;
}

Fixed &Fixed::operator--(void)
{
	this->fixedPointVal--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->fixedPointVal++;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->fixedPointVal--;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a,const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a,const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
