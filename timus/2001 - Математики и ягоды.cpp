#include <iostream>
#include <fstream>
#include <math.h>

int main() {
	int a1, a2, a3;
	int b1, b2, b3;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif

	std::cin >> a1 >> b1;
	std::cin >> a2 >> b2;
	std::cin >> a3 >> b3;

	std::cout	<< a1 - a3 << " "
				<< b1 - b2;

	return 0;
}