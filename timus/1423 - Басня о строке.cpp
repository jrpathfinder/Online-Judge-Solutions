#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int KMP(std::string& haystack, int begin, std::string& needle){
	std::vector<int> pf (needle.size());

	pf[0] = 0;
	for (int k = 0, i = 1; i < needle.size(); ++i){
		while(k > 0 && needle[i] != needle[k])
			k = pf[k - 1];

		if (needle[i] == needle[k])
			k++;

		pf[i] = k;
	}

	for (int k = 0, i = begin; i < haystack.size(); ++i) {
		while ((k > 0) && (needle[k] != haystack[i]))
			k = pf[k - 1];

		if (needle[k] == haystack[i])
			k++;

		if (k == needle.size())
			return (i - needle.size() + 1);
	}

	return -1;
}

int main() {
	int n;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif

	std::cin >> n;

	std::string source;
	std::string target;

	std::cin >> source;
	std::cin >> target;

	if(source == target) {
		std::cout << 0 << std::endl;
		return 0;
	}
		

	std::string s2(source.cbegin(), source.cend());
	
	s2 += source;

	int pos = KMP(s2, 0, target);
	if(pos == -1) {
		std::cout << pos << std::endl;
		return 0;
	}
		
	std::cout << n - KMP(s2, 0, target) << std::endl;

	return 0;
}