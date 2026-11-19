#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter {
public:
  static void convert(std::string const &literal);

private:
  ScalarConverter();
  ScalarConverter(ScalarConverter const &other);
  ScalarConverter &operator=(ScalarConverter const &other);
  ~ScalarConverter();
};

#endif
