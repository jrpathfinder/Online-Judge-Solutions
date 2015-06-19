#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <math.h>

static std::map<char, int> mp;

int main() {
	mp['A'] = 1;	mp['B'] = 2;	mp['D'] = 3;
	mp['P'] = 1;	mp['M'] = 2;	mp['G'] = 3;
	mp['R'] = 1;	mp['S'] = 2;	mp['J'] = 3;
	mp['O'] = 1;					mp['K'] = 3;
									mp['T'] = 3;
									mp['W'] = 3;
	int n;
	int steps = 0;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif
	std::string buff;
	int last_pos = 1;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> buff;
		int curr_pos = mp[buff[0]];
		steps += abs(last_pos-curr_pos);
		last_pos = curr_pos;

	}
	std::cout << steps;

	return 0;
}