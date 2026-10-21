#include "Sed.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Usage: ./sed_id_for_losers <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	Sed sedFile(argv[1]);
	sedFile.ft_sed(argv[2], argv[3]);
	return 0;
}