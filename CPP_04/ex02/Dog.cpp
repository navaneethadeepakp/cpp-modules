#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal() {
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    this->brain = new Brain(*(other.brain));
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other)
    {
        Animal::operator=(other);
        *(this->brain) = *(other.brain);
        std::cout << "Dog copy assignment operator called" << std::endl;
    }
    return (*this);
}

void Dog::makeSound() const {
    std::cout << type << " makes sound Dog" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

std::string Dog::getIdea(int index) const {
    return this->brain->getIdea(index);
}

void Dog::setIdea(std::string idea, int index) {
    this->brain->setIdea(idea, index);
}