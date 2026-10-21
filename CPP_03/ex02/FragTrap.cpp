#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap default constructor called" << this->name << std::endl;
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name) {
    std::cout << "FragTrap constructor called" << this->name << std::endl;
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap& other) {
    if (this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "FragTrap copy assignment operator called" << std::endl;
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called for " << name << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " Says : Hey everyone, positive high-fives all around" << std::endl;
}
