#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
  std::srand(std::time(NULL));

  Intern someRandomIntern;
  Bureaucrat boss("Boss", 1);
  AForm *form = NULL;

  std::cout << "----Testing Intern: RobotomyRequestForm----" << std::endl;
  form = someRandomIntern.makeForm("robotomy request", "roboform");
  if (form) {
    boss.signForm(*form);
    boss.executeForm(*form);
    delete form;
  }

  std::cout << "-----------------------------------------------\n" << std::endl;

  std::cout << "----Testing Intern: ShrubberyCreationForm----" << std::endl;
  form = someRandomIntern.makeForm("shrubbery creation", "garden");
  if (form) {
    boss.signForm(*form);
    boss.executeForm(*form);
    delete form;
  }

  std::cout << "-----------------------------------------------\n" << std::endl;

  std::cout << "----Testing Intern: PresidentialPardonForm----" << std::endl;
  form = someRandomIntern.makeForm("presidential pardon", "presidentform");
  if (form) {
    boss.signForm(*form);
    boss.executeForm(*form);
    delete form;
  }

  std::cout << "-----------------------------------------------\n" << std::endl;

  std::cout << "----Testing Intern: Unknown / Invalid Form----" << std::endl;
  form = someRandomIntern.makeForm("coffee request", "Boss");
  if (form) {
    boss.signForm(*form);
    boss.executeForm(*form);
    delete form;
  } else {
    std::cout << "Safely handled NULL: Form was not created." << std::endl;
  }

  return 0;
}
