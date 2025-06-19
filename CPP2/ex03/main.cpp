#include "Point.hpp"

int main(void)
{
	Point a(1.0,1.0);
	Point b;
	Point c(0.0, 2.0);
	Point p(0.5,0.5);
	if (bsp(a,b,c,p) == true)
		std::cout << "True" << std::endl;
	else
		std::cout << "False\n";
	return 0;
}