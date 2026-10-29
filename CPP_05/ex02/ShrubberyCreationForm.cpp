#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("default") {
  std::cout << "default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {
  std::cout << "Parametrized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) {
  std::cout << "Copy constructor called" << std::endl;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other)
    AForm::operator=(other);
  std::cout << "Copy assignment operator called" << std::endl;
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "Destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const { return this->target; }

const char *ShrubberyCreationForm::FileOpenException::what() const throw() {
  return "Could not open output file";
}

void ShrubberyCreationForm::executeAction() const {
  std::string filename = this->target + "_shrubbery";
  std::ofstream outFile(filename.c_str());

  if (!outFile.is_open()) {
    throw ShrubberyCreationForm::FileOpenException();
  }

  for (int i = 0; i < 3; i++)
    outFile << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\\n" << std::endl;
  outFile.close();
}
