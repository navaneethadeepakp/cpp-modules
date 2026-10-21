#include <iostream>
#include <string>

int main() {
	std::string stringVar = "HI THIS IS BRAIN";
	std::string *stringPTR = &stringVar;
	std::string &stringREF = stringVar;

	std::cout << "--- Memory Addresses ---" << std::endl;
	std::cout << "Address of the string variable: " << &stringVar << std::endl;
	std::cout << "Address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Address held by stringREF: " << &stringREF << std::endl;

	std::cout << "----------------------------------\n" << std::endl;

	std::cout << "--- Values ---" << std::endl;
	std::cout << "Value of the string variable: " << stringVar << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

	return 0;
}