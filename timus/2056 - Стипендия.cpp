#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

std::vector<int> marks;

int main() {
	int n;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif

	bool isNamed = true;
	bool isNone = false;

	std::cin >> n;
	for(int i = 0; i < n; i++) {
		int a;
		std::cin >> a;

		if(isNamed) 
			isNamed = (a == 5) ? true : false;

		if(!isNone)
			isNone = (a == 3) ? true : false;

		marks.push_back(a);
	}

	if(isNamed)
		std::cout << "Named";
	else if(isNone)
		std::cout << "None"; 
	else if( std::accumulate(marks.begin(), marks.end(), 0) / (double) marks.size() >= 4.5  )
		std::cout << "High";
	else
		std::cout << "Common";
	
	
	
	return 0;
}