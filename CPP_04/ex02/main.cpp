#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"

int main() {
    std::cout << "----array of animal----\n" << std::endl;
    const int size = 4;
    Animal* animals[size];
    for(int k = 0; k < size/2 ; k++)
    {
        std::cout << "---creatring dogs---" << std::endl;
        animals[k] = new Dog();
    }
    for(int k = 2; k < size ; k++)
    {
        std::cout << "\n---creatring cats---" << std::endl;
        animals[k] = new Cat();
    }
    animals[1]->makeSound();
    animals[2]->makeSound();
    for(int k = 0; k < size ; k++)
    {
        std::cout << "\n---deleting animal:" << k << std::endl;
        delete animals[k];
    }

    std::cout << "\n-----deep copy------" << std::endl;
    Dog* dog1 = new Dog();
    dog1->setIdea("I want food", 0);

    std::cout << "\n----copying a dog using copy constructor-----" << std::endl;
    Dog* dog2 = new Dog(*dog1);
    std::cout << "\n--------------------" << std::endl;
    std::cout << "dog1 idea:" << dog1->getIdea(0) << std::endl;
    std::cout << "dog2 idea:" << dog2->getIdea(0) << std::endl;

    std::cout << "\n----changing the dog1 idea----" << std::endl;
    dog1->setIdea("I want to sleep", 0);

    std::cout << "dog1 idea:" << dog1->getIdea(0) << std::endl;
    std::cout << "dog2 idea:" << dog2->getIdea(0) << std::endl;

    std::cout << "\n----deleting dogs-----" << std::endl;
    delete dog1;
    delete dog2;

    std::cout << "\n-----deep copy using copy assignmnet opeartor------" << std::endl;
    Cat* catA = new Cat();
    Cat* catB = new Cat();

    catA->setIdea("I am cat A", 0);
    catB->setIdea("I am cat B", 0);
    std::cout << "\n--------getting ides of cats------------" << std::endl;
    std::cout << "CatA idea:" << catA->getIdea(0) << std::endl;
    std::cout << "catB idea:" << catB->getIdea(0) << std::endl;
    std::cout << "\n------copy assignment operator called------" << std::endl;
    *(catB) = *(catA);
    std::cout << "\n---------after copying getting ides of cats-----------" << std::endl;
    std::cout << "CatA idea:" << catA->getIdea(0) << std::endl;
    std::cout << "catB idea:" << catB->getIdea(0) << std::endl;
    std::cout << "\n---------changing the value of catA-----------" << std::endl;
    catA->setIdea("I want to play", 0);
    std::cout << "CatA idea:" << catA->getIdea(0) << std::endl;
    std::cout << "catB idea:" << catB->getIdea(0) << std::endl;
    std::cout << "\n----deleting dogs-----" << std::endl;
    delete catA;
    delete catB;

    std::cout << "\n-------deep copy using stack object------" << std::endl;
    Dog stackDogA;
    stackDogA.setIdea("I am a stack dog", 0);
    Dog stackDogB(stackDogA);
    std::cout << "stackDogA idea:" << stackDogA.getIdea(0) << std::endl;
    std::cout << "stackDogB idea:" << stackDogB.getIdea(0) << std::endl;
    Dog stackDogC;
    stackDogC.setIdea("I am a another stack dog", 0);
    std::cout << "stackDogC idea:" << stackDogC.getIdea(0) << std::endl;
    stackDogC = stackDogA;
    std::cout << "stackDogC idea:" << stackDogC.getIdea(0) << std::endl;

    std::cout << "\n-------tetsing WrongAnimal--------" << std::endl;
    WrongAnimal* wrongPtr = new WrongCat();
    std::cout << wrongPtr->getType() << std::endl;
    wrongPtr->makeSound();
    delete wrongPtr;
    
    return 0;
}