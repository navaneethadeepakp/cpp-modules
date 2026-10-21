#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    fixedPointVal = 0;
}

Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointVal = n << this->fractBits;
}

Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointVal = roundf(f * (1 << fractBits));
}

Fixed::Fixed(const Fixed &original)
{
    std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

Fixed &Fixed::operator = (const Fixed &original)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &original)
    {
        this->fixedPointVal = original.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

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

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
