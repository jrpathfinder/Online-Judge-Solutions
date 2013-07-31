#include <iostream>
#include <set>
#include <string>
#include <iterator>

int main() {
	int n;
	std::cin >> n;

	std::set<std::string> setString;
	std::string buffer;
	for(size_t i = 0; i < n; i++) {
		std::cin >> buffer;
		setString.insert(buffer);
	}

	std::string inputSymbol;
	std::cin >> inputSymbol;

	for(std::set<std::string>::iterator p = setString.begin(); p != setString.end(); p++) {
		if( strncmp( p->c_str(), inputSymbol.c_str(), inputSymbol.size() ) == 0 )
			std::cout << p->c_str() << std::endl;
	}

	return 0;
}