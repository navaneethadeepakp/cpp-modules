#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() { std::cout << "default constructor called" << std::endl; }

Intern::Intern(const Intern &other) {
  (void)other;
  std::cout << "Copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
  (void)other;
  std::cout << "Copy assignment operator called" << std::endl;
  return *this;
}

Intern::~Intern() { std::cout << "Destructor called" << std::endl; }

AForm *Intern::makeShrubbery(const std::string &target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomy(const std::string &target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidential(const std::string &target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
  std::string names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
  AForm *(Intern::*creators[])(const std::string &) = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential};
  for (int i = 0; i < 3; i++) {
    if (formName == names[i]) {
      std::cout << "Intern creates " << formName << std::endl;
      return (this->*creators[i])(target);
    }
  }
  std::cout << "Error: Intern cannot create unknown form " << formName << std::endl;
  return NULL;
}
