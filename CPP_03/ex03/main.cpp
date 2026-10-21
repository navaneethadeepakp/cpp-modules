#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "----no parameter----" << std::endl;
    DiamondTrap defaultMonster;
    defaultMonster.whoAmI();

    std::cout << "\n----with parameter----" << std::endl;
    DiamondTrap sven("Sven");
    sven.whoAmI();

    sven.attack("dummy");
    sven.takeDamage(50);
    sven.beRepaired(25);
    sven.guardGate();
    sven.highFivesGuys();

    std::cout << "\n----mcopying object----" << std::endl;
    DiamondTrap cloneSven(sven);
    cloneSven.whoAmI();

    std::cout << "\n----with parameter----" << std::endl;
    DiamondTrap anotherMonster("Bob");
    anotherMonster.whoAmI();

    std::cout << "\n----assigning object----" << std::endl;
    anotherMonster = sven;
    anotherMonster.whoAmI();
    return 0;
}