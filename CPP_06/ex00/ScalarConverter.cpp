#include "ScalarConverter.hpp"

#include <cctype>
#include <cerrno>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <sstream>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
  (void)other;
  return *this;
}
ScalarConverter::~ScalarConverter() {}

static bool isPseudoFloat(std::string const &s) {
  return s == "nanf" || s == "+inff" || s == "-inff" || s == "inff";
}

static bool isPseudoDouble(std::string const &s) {
  return s == "nan" || s == "+inf" || s == "-inf" || s == "inf";
}

static bool isChar(std::string const &s) {
  if (s.length() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])))
    return true;
  if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
    return true;
  return false;
}

static bool isInt(std::string const &s) {
  std::size_t i = 0;

  if (s[i] == '+' || s[i] == '-')
    i++;
  if (i == s.length())
    return false;
  for (; i < s.length(); i++) {
    if (!std::isdigit(static_cast<unsigned char>(s[i])))
      return false;
  }
  return true;
}

static bool isDecimal(std::string const &s) {
  std::size_t i = 0;
  int dots = 0;
  int digits = 0;

  if (s.empty())
    return false;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (; i < s.length(); i++) {
    if (s[i] == '.')
      dots++;
    else if (std::isdigit(static_cast<unsigned char>(s[i])))
      digits++;
    else
      return false;
  }
  return dots == 1 && digits > 0;
}

static bool isFloat(std::string const &s) {
  return s.length() > 1 && s[s.length() - 1] == 'f' &&
         isDecimal(s.substr(0, s.length() - 1));
}

static bool isDouble(std::string const &s) { return isDecimal(s); }

static bool isNan(double d) { return d != d; }

static bool isInf(double d) {
  return d == std::numeric_limits<double>::infinity() ||
         d == -std::numeric_limits<double>::infinity();
}

static void printImpossible() {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: impossible" << std::endl;
  std::cout << "double: impossible" << std::endl;
}

static void printCharValue(char c) {
  if (std::isprint(static_cast<unsigned char>(c)))
    std::cout << "char: '" << c << "'" << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;
}

static void printFloatValue(float f) {
  std::cout << "float: ";
  if (isNan(f))
    std::cout << "nanf";
  else if (isInf(f))
    std::cout << (f > 0 ? "+inff" : "-inff");
  else {
    std::ostringstream oss;
    if (f == std::floor(f) && std::fabs(f) < 1e7f)
      oss << std::fixed << std::setprecision(1);
    oss << f;
    std::cout << oss.str() << "f";
  }
  std::cout << std::endl;
}

static void printDoubleValue(double d) {
  std::cout << "double: ";
  if (isNan(d))
    std::cout << "nan";
  else if (isInf(d))
    std::cout << (d > 0 ? "+inf" : "-inf");
  else {
    std::ostringstream oss;
    if (d == std::floor(d) && std::fabs(d) < 1e16)
      oss << std::fixed << std::setprecision(1);
    oss << d;
    std::cout << oss.str();
  }
  std::cout << std::endl;
}

static void castAndPrint(char actual) {
  int i = static_cast<int>(actual);
  float f = static_cast<float>(actual);
  double d = static_cast<double>(actual);

  printCharValue(actual);
  std::cout << "int: " << i << std::endl;
  printFloatValue(f);
  printDoubleValue(d);
}

static void castAndPrint(int actual) {
  if (actual < 0 || actual > 127)
    std::cout << "char: impossible" << std::endl;
  else
    printCharValue(static_cast<char>(actual));

  std::cout << "int: " << actual << std::endl;
  printFloatValue(static_cast<float>(actual));
  printDoubleValue(static_cast<double>(actual));
}

static void castAndPrint(float actual) {
  double check = static_cast<double>(actual);

  if (isNan(check) || isInf(check) || check < 0 || check > 127)
    std::cout << "char: impossible" << std::endl;
  else
    printCharValue(static_cast<char>(actual));

  if (isNan(check) || isInf(check) || check < INT_MIN || check > INT_MAX)
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << static_cast<int>(actual) << std::endl;

  printFloatValue(actual);
  printDoubleValue(static_cast<double>(actual));
}

static void castAndPrint(double actual) {
  if (isNan(actual) || isInf(actual) || actual < 0 || actual > 127)
    std::cout << "char: impossible" << std::endl;
  else
    printCharValue(static_cast<char>(actual));

  if (isNan(actual) || isInf(actual) || actual < INT_MIN || actual > INT_MAX)
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << static_cast<int>(actual) << std::endl;

  if (!isNan(actual) && !isInf(actual) && std::fabs(actual) > FLT_MAX)
    std::cout << "float: impossible" << std::endl;
  else
    printFloatValue(static_cast<float>(actual));

  printDoubleValue(actual);
}

void ScalarConverter::convert(std::string const &literal) {
  if (literal.empty()) {
    printImpossible();
    return;
  }
  if (isPseudoFloat(literal)) {
    float actualFloat;
    if (literal == "nanf")
      actualFloat = std::numeric_limits<float>::quiet_NaN();
    else if (literal[0] == '-')
      actualFloat = -std::numeric_limits<float>::infinity();
    else
      actualFloat = std::numeric_limits<float>::infinity();
    castAndPrint(actualFloat);
  } else if (isPseudoDouble(literal)) {
    double actualDouble;
    if (literal == "nan")
      actualDouble = std::numeric_limits<double>::quiet_NaN();
    else if (literal[0] == '-')
      actualDouble = -std::numeric_limits<double>::infinity();
    else
      actualDouble = std::numeric_limits<double>::infinity();
    castAndPrint(actualDouble);
  } else if (isChar(literal)) {
    char actualChar = (literal.length() == 3) ? literal[1] : literal[0];
    castAndPrint(actualChar);
  } else if (isInt(literal)) {
    errno = 0;
    long tmp = std::strtol(literal.c_str(), NULL, 10);
    if (errno == ERANGE || tmp < INT_MIN || tmp > INT_MAX) {
      double actualDouble = std::strtod(literal.c_str(), NULL);
      if (isInf(actualDouble)) {
        printImpossible();
        return;
      }
      castAndPrint(actualDouble);
      return;
    }
    int actualInt = static_cast<int>(tmp);
    castAndPrint(actualInt);
  } else if (isFloat(literal)) {
    double tmp = std::strtod(literal.c_str(), NULL);
    if (std::fabs(tmp) > FLT_MAX) {
      if (isInf(tmp)) {
        printImpossible();
        return;
      }
      castAndPrint(tmp);
      return;
    }
    float actualFloat = static_cast<float>(tmp);
    castAndPrint(actualFloat);
  } else if (isDouble(literal)) {
    double actualDouble = std::strtod(literal.c_str(), NULL);
    if (isInf(actualDouble)) {
      printImpossible();
      return;
    }
    castAndPrint(actualDouble);
  } else
    printImpossible();
}