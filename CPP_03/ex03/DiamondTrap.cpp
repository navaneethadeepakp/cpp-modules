#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("unnamed_clap_name"), ScavTrap(), FragTrap(), name("unnamed") {
    std::cout << "DiamondTrap default constructor called " << name << std::endl;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 30;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name) {
    std::cout << "DiamondTrap constructor called " << name << std::endl;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap &other)
{
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this != &other)
    {
       ClapTrap::operator=(other);
       this->name = other.name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called for " << name << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}
