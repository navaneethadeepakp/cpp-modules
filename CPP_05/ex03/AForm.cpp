#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
  std::cout << "default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign),
      gradeToExecute(gradeToExecute) {
  if (this->gradeToSign < 1 || this->gradeToExecute < 1)
    throw AForm::GradeTooHighException();
  if (this->gradeToSign > 150 || this->gradeToExecute > 150)
    throw AForm::GradeTooLowException();
  std::cout << "Parametrized constructor called" << std::endl;
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
  std::cout << "Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other)
    this->isSigned = other.isSigned;
  std::cout << "Copy assignment operator called" << std::endl;
  return *this;
}

AForm::~AForm() { std::cout << "Destructor called" << std::endl; }

std::string AForm::getName() const { return this->name; }
bool AForm::getIsSigned() const { return this->isSigned; }
int AForm::getGradeToSign() const { return this->gradeToSign; }
int AForm::getGradeToExecute() const { return this->gradeToExecute; }

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade is too High";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade is too Low";
}

const char *AForm::FormNotSignedException::what() const throw() {
  return "AForm is not signed";
}

void AForm::beSigned(const Bureaucrat &b) {
  if (b.getGrade() <= this->gradeToSign)
    this->isSigned = true;
  else
    throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const {
  if (!this->isSigned)
    throw AForm::FormNotSignedException();
  if (executor.getGrade() > this->gradeToExecute)
    throw GradeTooLowException();
  this->executeAction();
}

std::ostream &operator<<(std::ostream &os, const AForm &f) {
  os << "AForm: " << f.getName() << ", signed: " << std::boolalpha
     << f.getIsSigned() << ", sign grade: " << f.getGradeToSign()
     << ", exec grade: " << f.getGradeToExecute() << ".";
  return os;
}