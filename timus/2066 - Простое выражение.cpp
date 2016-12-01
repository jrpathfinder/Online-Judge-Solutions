#include <iostream>

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;

	if(a == 1 && b == 1) 		std::cout << a - b - c;
	else if(a == 0 && b == 0)	std::cout << a - b - c;
	else if(a == 0 && b == 1)	std::cout << a - b - c;
	else						std::cout << a - b * c;

	return 0;
}