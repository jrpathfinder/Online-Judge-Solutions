#include <iostream>
#include <fstream>
#include <string>

int main() {
	int n = 0;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif
	
	std::string str;
	std::cin >> str;

	for(int i = 0; i < str.size(); i++) {
		n = ( n * 10 + str[i] - '0' ) % 7;
	}

	std::cout << n << std::endl;

	return 0;
}