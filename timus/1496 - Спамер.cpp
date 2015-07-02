#include <iostream>
#include <fstream>
#include <string>
#include <map>

std::map<std::string, int> accounts;

int main() {
	int n;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif
	
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::string buff;
		std::cin >> buff;
		accounts[buff]++;
	}

	for(auto p = accounts.begin(); p != accounts.end(); p++) {
		if( p->second > 1 )
			std::cout << p->first << std::endl;
	}

	return 0;
}