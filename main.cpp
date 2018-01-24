#include "SquareSum.h"
#include <iostream>
#include <limits>


int main()
{
	int vertices = 1;

	std::cout << "How many vertices do you want in the Square Sum graph (int)? ";
	std::cin >> vertices;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	SquareSum ss(vertices);
	
	std::cout << "The application is done running";
	std::cin.get();

	return 0;
}