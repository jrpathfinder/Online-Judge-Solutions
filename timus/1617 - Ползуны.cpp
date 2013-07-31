#include <iostream>
#include <iterator>
#include <map>

int main() {
	int n;
	std::map<int, int> mp;

	std::cin >> n;
	
	int buffer = 0;
	for(size_t i = 0; i < n; i++) {
		std::cin >> buffer;
		mp[buffer]++;
	}

	int count = 0;
	for(std::map<int, int>::iterator p = mp.begin(); p != mp.end(); p++) {
		//if(p->first >= 600)
			count += (int)(p->second / 4);
	}

	std::cout << count << std::endl;
	
	return 0;
}