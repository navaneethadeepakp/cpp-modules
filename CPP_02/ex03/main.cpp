#include "Point.hpp"

int main()
{
	Point a(0,0);
	Point b(10,0);
	Point c(5,10);
	Point p(5,5);

	if (bsp(a,b,c,p))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;
	return 0;
}