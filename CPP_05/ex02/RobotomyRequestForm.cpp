#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("default") {
  std::cout << "default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {
  std::cout << "Parametrized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target) {
  std::cout << "Copy constructor called" << std::endl;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this != &other)
    AForm::operator=(other);
  std::cout << "Copy assignment operator called" << std::endl;
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "Destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const { return this->target; }

void RobotomyRequestForm::executeAction() const {
  std::cout << "* DRILLING NOISES... BZZZZZT! VRRRRRR! *" << std::endl;

  if (std::rand() % 2 == 0)
    std::cout << this->target << " has been robotomized successfully."
              << std::endl;
  else
    std::cout << "Robotomy on " << this->target << " has failed." << std::endl;
}