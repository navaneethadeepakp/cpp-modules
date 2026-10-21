#include "ClapTrap.hpp"

int main()
{
    ClapTrap defaultRobo;
    ClapTrap myRobo("Bot1");
    myRobo.attack("Bot2");
    myRobo.takeDamage(5);
    myRobo.beRepaired(3);
    myRobo.takeDamage(10);
    myRobo.attack("bot3");
    return 0;
}