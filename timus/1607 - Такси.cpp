#include <iostream>
#include <fstream>
#include <algorithm>

int main() {
	int a, b, c, d;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif
	std::cin >> a >> b >> c >> d;

	if(a > c) {std::cout << a; return 0;}

	int min = a + (c - a) / (b + d) * b;
	int max = c - (c - a) / (b + d) * d;

	min = std::min(min + b, max);
	max = std::max(max - d, min);

	std::cout << max << std::endl;
	
	return 0;
}