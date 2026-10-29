#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  std::cout << "----Successful Form signing----" << std::endl;
  try {
    Bureaucrat b1("b1", 20);
    Form f1("f1", 50, 15);
    std::cout << b1 << std::endl;
    std::cout << f1 << std::endl;
    std::cout << "b1 attempts to sign form f1" << std::endl;
    b1.signForm(f1);
  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << "-----------------------------------------------\n" << std::endl;

  std::cout << "----Failed Form signing----" << std::endl;
  try {
    Bureaucrat b2("b2", 100);
    Form f2("f2", 25, 10);
    std::cout << b2 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << "b2 attempts to sign form f2" << std::endl;
    b2.signForm(f2);
  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << "-----------------------------------------------\n" << std::endl;

  std::cout << "----Calling beSigned directly----" << std::endl;
  try {
    Bureaucrat b3("b3", 80);
    Form f3("f3", 40, 20);
    f3.beSigned(b3);
  } catch (std::exception &e) {
    std::cout << "Direct Exception caught: " << e.what() << std::endl;
  }

  std::cout << "-----------------------------------------------\n" << std::endl;

  std::cout << "----From grade out of bounds test----" << std::endl;
  try {
    Form f4("f4", 0, 50);
  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  try {
    Form f4("f4", 70, 151);
  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << "-----------------------------------------------\n" << std::endl;

  std::cout << " ----Using copy constructor and copy assignment operator----"
            << std::endl;
  try {
    Bureaucrat originalBureaucrat("originalBureaucrat", 10);
    Form originalForm("originalForm", 50, 40);
    originalBureaucrat.signForm(originalForm);

    std::cout << "Original Form: " << originalForm << std::endl;

    Form copyForm(originalForm);
    std::cout << "Copied Form: " << copyForm << std::endl;

    Form assignedForm("temp", 100, 100);
    std::cout << "Before assignment: " << assignedForm << std::endl;

    assignedForm = originalForm;
    std::cout << "After assignment: " << assignedForm << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
  return 0;
}
