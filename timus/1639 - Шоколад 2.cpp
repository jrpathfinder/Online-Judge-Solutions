#include <iostream>
#include <fstream>

int main() {
	int m, n;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif

	std::cin >> m >> n;
	
	if( m%2 == 1 && n%2 == 1 )
		std::cout << "[second]=:]" << std::endl;
	else
		std::cout << "[:=[first]" << std::endl;

	return 0;
}