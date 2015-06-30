#include <iostream>
#include <fstream>
#include <string>
#include <map>

std::map<std::string, int> mp;

int main() {
	int n;
	std::string str = "";
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif
	std::cin >> n;
	getline(std::cin, str);
	for(int i = 0; i < n; i++) {
		getline(std::cin, str);
		mp[str]++;
	}

	unsigned int currentMax = 0;
	std::string arg_max = "";
	for(auto it = mp.begin(); it != mp.end(); ++it ) {
		if (it->second > currentMax) {
			arg_max = it->first;
			currentMax = it->second;
		}
	}

	std::cout << arg_max;

	return 0;
}