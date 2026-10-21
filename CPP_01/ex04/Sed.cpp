#include "Sed.hpp"
#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>

Sed::Sed(std::string filename) : _inFile(filename), _outFile(filename + ".replace") {}
Sed::~Sed() {}

void Sed::ft_sed(std::string s1, std::string s2) {
	if (s1.empty()) {
		std::cerr << "Error: Search string s1 cannot be empty." << std::endl;
		return ;
	}
	std::ifstream ifs(_inFile.c_str());
	if (!ifs.is_open()) {
		std::cerr << "Error: Unable to open input file: " << _inFile << " - " << std::strerror(errno) << std::endl;
		return ;
	}
	std::ofstream ofs(_outFile.c_str());
	if (!ofs.is_open()) {
		std::cerr << "Error: Unable to create output file: " << _outFile << " - " << std::strerror(errno) << std::endl;
		ifs.close();
		return ;
	}
	std::string line;
	while (std::getline(ifs, line)) {
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		ofs << line;
		if (!ifs.eof())
			ofs << '\n';
	}
	ifs.close();
	ofs.close();
}