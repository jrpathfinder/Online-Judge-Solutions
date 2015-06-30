#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main() {
	int n, k;
	std::vector<std::vector<int>> a;

#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif
	std::cin >> n >> k;
	
	for(int i = 0; i < n; i++) {
		std::vector<int> buf;
		int buf2, buf3;
		std::cin >> buf2 >> buf3;
		buf.push_back(buf2); buf.push_back(buf3);
		a.push_back(buf);
	}

	int must = 0;
	int have = 0;

	for(int i = 0; i < n; i++) {
		must += a[i][0] - 2;
		have += a[i][1];
	}

	must += k - 2;

	if(must - have >= 0) std::cout << must - have;
	else std::cout << "Big Bang!";

	return 0;
}