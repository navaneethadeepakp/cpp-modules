#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap default constructor called " << this->name << std::endl;
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "ScavTrap constructor called " << this->name << std::endl;
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
       std::cout << "ScavTrap assignment operator called" << std::endl;
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called for " << name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (energy_points > 0 && hit_points > 0)
    {
        energy_points--;
        std::cout << "ScavTrap " << name << " attacks " << target << " causing " << attack_damage << " points of damage." << std::endl;
    }
    else
         std::cout << "ScavTrap " << name << " has no energy or hit points left to attack." << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}