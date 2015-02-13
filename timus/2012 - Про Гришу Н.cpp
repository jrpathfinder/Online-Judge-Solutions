#include <iostream>

#define TIME 5
#define TASKS 12

int main() {
	int f;
	std::cin >> f;

	if( 45 * (TASKS - f) <= 4 * 60 ) std::cout << "YES";
	else std::cout << "NO";

	return 0;

}