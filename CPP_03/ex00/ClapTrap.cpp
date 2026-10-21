#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("unnamed"), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap default constructor called " << std::endl;
}

ClapTrap::ClapTrap(const std::string& rName): name(rName), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap constructor called " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hit_points(other.hit_points), energy_points(other.energy_points), attack_damage(other. attack_damage)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &other)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (energy_points > 0 && hit_points > 0)
    {
        energy_points--;
        std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attack_damage << " points of damage." << std::endl;
    }
    else
         std::cout << "ClapTrap " << name << " has no energy or hit points left to attack." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= hit_points)
        hit_points = 0;
    else
        hit_points -= amount;
    std::cout << "ClapTrap " << name << " took " << amount << " damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energy_points > 0 && hit_points > 0)
    {
        energy_points--;
        hit_points += amount;
        std::cout << "ClapTrap " << name << " repaired itself for " << amount << " points!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << name << " cannot repair (no energy or HP)." << std::endl;
    }
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called for " << name << std::endl;
}