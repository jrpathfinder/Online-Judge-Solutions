#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main() {
	int n, k;
	std::vector<int> a;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif
	std::cin >> n >> k;
	int buff;
	for(;!std::cin.eof();) {
		std::cin >> buff;
		a.push_back(buff);
	}
	
	int droids = n * k;
	int boom = 0;

	for(int i = 0; i < n; i++) {
		droids	= (a[i] <= k) ? droids - a[i] : droids - k;
		boom	= (a[i] - k >= 0) ? boom + a[i] - k : boom;
	}

	std::cout << boom << " " << droids;

	return 0;
}