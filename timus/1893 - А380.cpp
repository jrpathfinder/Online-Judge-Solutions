#include <iostream>
#include <fstream>
#include <string>

std::string premium		= "1x0xx0x1";
std::string buisness	= "1xx0xx0xx1";
std::string econom		= "1xxx0xxxx0xxx1";


int main() {
	std::string place;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif

	std::cin >> place;

	int row = atoi( place.substr(0, place.size() - 1).c_str() );

	int iplace = place.substr(place.size() - 1)[0] - 'A' + 1;
	if(iplace > 8)
		iplace--;

	if(row <= 2) {
		if(iplace == 1 || iplace == 4)
			std::cout << "window";
		else
			std::cout << "aisle";

	} else if(row >= 3 && row <= 20) {
		if(iplace == 1 || iplace == 6)
			std::cout << "window";
		else
			std::cout << "aisle";

	} else if(row >= 21 && row <= 65) {
		if(iplace == 1 || iplace == 10)
			std::cout << "window";
		else if (iplace == 3 || iplace == 4 || iplace == 7 || iplace == 8 ) 
			std::cout << "aisle";
		else
			std::cout << "neither";
	}

	return 0;
}