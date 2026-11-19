#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

void identify(Base *p) {
  if (dynamic_cast<A *>(p) != NULL)
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p) != NULL)
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p) != NULL)
    std::cout << "C" << std::endl;
  else
    std::cout << "Unknown" << std::endl;
}

void identify(Base &p) {
  try {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << "A" << std::endl;
    return;
  } catch (std::exception &) {
  }

  try {
    B &b = dynamic_cast<B &>(p);
    (void)b;
    std::cout << "B" << std::endl;
    return;
  } catch (std::exception &) {
  }
  try {
    C &c = dynamic_cast<C &>(p);
    (void)c;
    std::cout << "C" << std::endl;
    return;
  } catch (std::exception &) {
  }
  std::cout << "Unknown" << std::endl;
}

Base *generate() {
  int r = std::rand() % 3;

  if (r == 0)
    return new A();
  if (r == 1)
    return new B();
  return new C();
}

int main() {
  std::srand(static_cast<unsigned int>(std::time(NULL)));

  for (int i = 0; i < 6; i++) {
    Base *ptr = generate();
    std::cout << "Test: " << i + 1 << " -> ptr: ";
    identify(ptr);
    std::cout << "Test: " << i + 1 << " -> ptr: ";
    identify(*ptr);
    delete ptr;
  }
  std::cout << "Null ptr - > ";
  identify(NULL);
  return 0;
}