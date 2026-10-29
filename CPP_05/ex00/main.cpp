#include "Bureaucrat.hpp"

int main() {
  std::cout << "------Testing with valid grades------" << std::endl;
  try {
    Bureaucrat b1("b1", 3);
    std::cout << b1 << std::endl;

    b1.incrementGrade();
    std::cout << "After increment: " << b1 << std::endl;

    b1.decrementGrade();
    std::cout << "After decrement: " << b1 << std::endl;
  } catch (std::exception &e) {
    std::cout << "Error:" << e.what() << std::endl;
  }

  std::cout << "-----------------------------------------------\n" << std::endl;

  std::cout << "\n----Testing with high grade during construction----"
            << std::endl;
  try {
    Bureaucrat b2("b2", 0);
    std::cout << "b2" << b2 << std::endl;
  } catch (std::exception &e) {
    std::cout << "Error:" << e.what() << std::endl;
  }

  std::cout << "\n------Testing with low grade during construction------"
            << std::endl;
  try {
    Bureaucrat b3("b3", 151);
    std::cout << "b3:" << b3 << std::endl;
  } catch (std::exception &e) {
    std::cout << "Error:" << e.what() << std::endl;
  }

  std::cout << "-----------------------------------------------\n" << std::endl;

  std::cout << "\n----Testing beyond grade 1----" << std::endl;
  try {
    Bureaucrat b4("b4", 1);
    std::cout << b4 << std::endl;
    b4.incrementGrade();
    std::cout << b4 << std::endl;
  } catch (std::exception &e) {
    std::cout << "Error:" << e.what() << std::endl;
  }

  std::cout << "-----------------------------------------------\n" << std::endl;

  std::cout << "\n----Testing beyond grade 150----" << std::endl;
  try {
    Bureaucrat b5("b5", 150);
    std::cout << b5 << std::endl;
    b5.decrementGrade();
    std::cout << b5 << std::endl;
  } catch (std::exception &e) {
    std::cout << "Error:" << e.what() << std::endl;
  }

  std::cout << "-----------------------------------------------\n" << std::endl;

  std::cout << "----Using copy constructor and copy assignment operator----"
            << std::endl;
  try {
    Bureaucrat original("original", 10);
    std::cout << "Original: " << original << std::endl;
    Bureaucrat copyConstructed(original);
    std::cout << "Copied:   " << copyConstructed << std::endl;
    Bureaucrat assigned("temp", 100);
    std::cout << "Before assignment: " << assigned << std::endl;
    assigned = original;
    std::cout << "After assignment:  " << assigned << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  return 0;
}