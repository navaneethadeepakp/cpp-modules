#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    fixedPointVal = 0;
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
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointVal;
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPointVal = raw;
}
