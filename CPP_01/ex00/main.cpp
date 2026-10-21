#include "Zombie.hpp"

int main() {
	std::cout << "--- Creating a Stack Zombie via randomChump ---" << std::endl;
	randomChump("StackZombie");
	std::cout << "randomChump execution finished.\n" << std::endl;

	std::cout << "--- Creating a Heap Zombie via newZombie ---" << std::endl;
	Zombie *heapZombie = newZombie("HeapZombie");
	(*heapZombie).announce();
	std::cout << "Manually deleting Heap Zombie." << std::endl;
	delete heapZombie;
	return 0;
}