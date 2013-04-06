// 1126. Магнитные бури
// 0.234 s
// 0.234 Kb

#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>

int main()
{
	int		m;
	long	data[25005] = {-1};
	int		ilast;
	
	std::cin >> m;
	for(int i=0;std::cin>>data[i];i++)
		ilast = i;

	for(auto p=data; p + m!=data + ilast + 1; p++)
		std::cout << *std::max_element(p,p+m) << std::endl;

	return 0;
}