#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
  std::cout << "default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign),
      gradeToExecute(gradeToExecute) {
  if (this->gradeToSign < 1 || this->gradeToExecute < 1)
    throw Form::GradeTooHighException();
  if (this->gradeToSign > 150 || this->gradeToExecute > 150)
    throw Form::GradeTooLowException();
  std::cout << "Parametrized constructor called" << std::endl;
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
  std::cout << "Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other) {
  if (this != &other)
    this->isSigned = other.isSigned;
  std::cout << "Copy assignment operator called" << std::endl;
  return *this;
}

Form::~Form() { std::cout << "Destructor called" << std::endl; }

std::string Form::getName() const { return this->name; }
bool Form::getIsSigned() const { return this->isSigned; }
int Form::getGradeToSign() const { return this->gradeToSign; }
int Form::getGradeToExecute() const { return this->gradeToExecute; }

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade is too High";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade is too Low";
}

void Form::beSigned(const Bureaucrat &b) {
  if (b.getGrade() <= this->gradeToSign)
    this->isSigned = true;
  else
    throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &f) {
  os << "Form: " << f.getName() << ", signed: " << std::boolalpha
     << f.getIsSigned() << ", sign grade: " << f.getGradeToSign()
     << ", exec grade: " << f.getGradeToExecute() << ".";
  return os;
}