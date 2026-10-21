#include "FragTrap.hpp"

int main()
{
    FragTrap alpha("Alpha");
    FragTrap beta("Beta");
    FragTrap gama(alpha);
    std::cout <<"--------" << std::endl;

    beta = alpha;
    alpha.attack("Enemy_bot");
    alpha.takeDamage(20);
    alpha.highFivesGuys();
    return 0;

}