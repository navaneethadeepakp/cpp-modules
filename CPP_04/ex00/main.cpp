#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "------dynamic binding-----\n" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "\n-----copy constructor testing with dynamic binding-----" << std::endl;
    Dog* heapDog1 = new Dog();
    Dog* heapDog2 = new Dog(*heapDog1);
    Dog* heapDog3 = new Dog();
    *heapDog3 = *heapDog1;
    delete heapDog1;
    delete heapDog2;
    delete heapDog3;

    std::cout << "\n-----static biniding-----\n" << std::endl;
    WrongCat cat;
    WrongAnimal* ptr = new WrongCat();
    std::cout << ptr->getType() << std::endl;
    ptr->makeSound();
    cat.makeSound();
    delete ptr;
    
    std::cout << "\n-----copy constructor testing with static binding-----" << std::endl;
    WrongAnimal* ptr1 = new WrongCat();
    WrongAnimal* ptr2 = new WrongCat();
    *ptr2 = *ptr1;
    ptr1->makeSound();
    ptr2->makeSound();
    delete ptr1;
    delete ptr2;
    std::cout << "----" << std::endl;
    return 0;
}