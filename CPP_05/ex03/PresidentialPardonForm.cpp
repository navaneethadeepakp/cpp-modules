#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), target("default") {
  std::cout << "default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) {
  std::cout << "Parametrized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other), target(other.target) {
  std::cout << "Copy constructor called" << std::endl;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  if (this != &other)
    AForm::operator=(other);
  std::cout << "Copy assignment operator called" << std::endl;
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "Destructor called" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const { return this->target; }

void PresidentialPardonForm ::executeAction() const {
  std::cout << this->target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}