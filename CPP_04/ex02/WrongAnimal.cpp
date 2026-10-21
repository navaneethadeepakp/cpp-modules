#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

void WrongAnimal::makeSound() const {
    std::cout << type << " makes sound WrongAnimal" << std::endl;
}

std::string WrongAnimal::getType(void) const {
    return type;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

// --------------------------------------------------------------------------

WrongCat::WrongCat() : WrongAnimal() {
    type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this != &other)
    {
         WrongAnimal::operator=(other);
    }
    return (*this);
}

void WrongCat::makeSound() const {
    std::cout << type << " makes sound WrongCat" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}
