#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>

int main() {
	int n;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif
	std::cin >> n;

	if(n > 2 || n == 0) {
		std::cout << -1 << std::endl;
	} else if(n == 2) {
		std::cout << "3 4 5" << std::endl;
	} else if(n == 1) {
		std::cout << "1 2 3" << std::endl;
	}
	
	return 0;
}