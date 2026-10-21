#include "Zombie.hpp"

int main() {
	int hordeSize = 5;
	std::string hordeName = "Chomper";
	std::cout << "--- Creating a horde of " << hordeSize << " zombies ---" << std::endl;
	Zombie *myHorde = zombieHorde(hordeSize, hordeName);

	if (myHorde == NULL) {
		std::cout << "Failed to create horde." << std::endl;
		return 1;
	}

	std::cout << "\n--- Making the horde anounce themselves ---" << std::endl;
	for (int i = 0; i < hordeSize; i++)
	{
		std::cout << "[" << i << "] ";
		myHorde[i].announce();
	}

	std::cout << "\n--- Destroying the horde ---" << std::endl;
	delete[] myHorde;
}