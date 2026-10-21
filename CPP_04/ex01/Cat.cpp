#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal() {
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    this->brain = new Brain(*(other.brain));
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other)
    {
        Animal::operator=(other);
        *(this->brain) = *(other.brain);
        std::cout << "Cat copy assignment operator called" << std::endl;
    }
    return (*this);
}

void Cat::makeSound() const {
    std::cout << type << " makes sound Cat" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

std::string Cat::getIdea(int index) const {
    return this->brain->getIdea(index);
}

void Cat::setIdea(std::string idea, int index) {
    this->brain->setIdea(idea, index);
}