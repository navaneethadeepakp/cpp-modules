#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
  std::srand(std::time(NULL));

  std::cout << "----Testing ShrubberyCreationForm----" << std::endl;
  try {
    Bureaucrat b1("b1", 130);
    ShrubberyCreationForm f1("home");

    std::cout << b1 << std::endl;
    std::cout << f1 << std::endl;

    std::cout << "\nAttempting to execute before signing:" << std::endl;
    b1.executeForm(f1);

    std::cout << "\nSigning the form:" << std::endl;
    b1.signForm(f1);

    std::cout << "\nExecuting after signing:" << std::endl;
    b1.executeForm(f1);
  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << "-----------------------------------------------\n" << std::endl;

  std::cout << "----Testing RobotomyRequestForm----" << std::endl;
  try {
    Bureaucrat b2("b2", 40);
    Bureaucrat b3("b3", 60);
    RobotomyRequestForm f2("roboform");

    std::cout << b2 << std::endl;
    std::cout << f2 << std::endl;

    b3.signForm(f2);

    std::cout << "\nBureaucrat with grade 60 attempts to execute (needs 45):"
              << std::endl;
    b3.executeForm(f2);

    std::cout << "\nBureaucrat with grade 40 executes (50% test):" << std::endl;
    b2.executeForm(f2);
    b2.executeForm(f2);
    b2.executeForm(f2);
    b2.executeForm(f2);
  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << "-----------------------------------------------\n" << std::endl;

  std::cout << "----Testing PresidentialPardonForm----" << std::endl;
  try {
    Bureaucrat president("President", 1);
    Bureaucrat minister("Minister", 20);
    PresidentialPardonForm f3("presidentform");

    std::cout << president << std::endl;
    std::cout << f3 << std::endl;

    minister.signForm(f3);

    std::cout << "\nMinister (grade 20) attempts to execute (needs 5):"
              << std::endl;
    minister.executeForm(f3);

    std::cout << "\nPresident (grade 1) executes:" << std::endl;
    president.executeForm(f3);
  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  return 0;
}
