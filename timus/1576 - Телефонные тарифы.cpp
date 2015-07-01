#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main() {
	int N1, C1;
	int N2, T, C2;
	int N3;
	int K;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif
	std::cin >> N1 >> C1;
	std::cin >> N2 >> T >> C2;
	std::cin >> N3;
	std::cin >> K;
	
	int Basic = N1;
	int Combined = N2;
	int Unlimited = N3;

	int total = 0;

	std::string buff;
	getline(std::cin, buff);
	for(int i = 0; i < K; i++) {
		getline(std::cin, buff);

		std::string sminutes = buff.substr(0, buff.find(":"));
		std::string sseconds = buff.substr(buff.find(":") + 1);

		int minutes = atoi(sminutes.c_str());
		int seconds = atoi(sseconds.c_str());

		total += minutes;
		total += (minutes < 1) ? ((seconds < 7) ? 0 : 1 ) : ( (seconds > 0) ? 1 : 0 );

	}

	std::cout << "Basic:     " << N1 + C1 * total << std::endl;
	std::cout << "Combined:  " << N2 + ((total <= T) ? 0 : (total - T) * C2) << std::endl;
	std::cout << "Unlimited: " << N3 << std::endl;

	return 0;
}