#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

std::vector<int> numbers;
std::vector<int> simple_numbers;

int main() {
	int k;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif
	std::cin >> k;
	for(int i = 0; i < k; i++) {
		int num;
		std::cin >> num;
		numbers.push_back(num);
	}

	int max_num = *(std::max_element(numbers.begin(), numbers.end()));

	simple_numbers.push_back(2);

	bool isSimple = true;
	for(int i = 3; ; i++) {
		
		for(int j = 2; j <= sqrt((float) i) + 1; j++) {
			if( i % j == 0 ) {
				isSimple = false;
				break;
			}
		}

		if(isSimple)
			simple_numbers.push_back(i);

		isSimple = true;

		if(simple_numbers.size() == max_num)
			break;
	}

	for(int i = 0; i < numbers.size(); i++) {
		std::cout << simple_numbers[numbers[i]-1] << std::endl;
	}

	return 0;
}