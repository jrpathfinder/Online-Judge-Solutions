#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>

int main()
{
	int		n;
	long	door[1001];

	std::cin >> n;
	for(int i=0;i<n;i++)
		std::cin >> door[i];

	long summ = 0;
	auto pg = &door[0];
	for(auto p = door + 1;p!=&door[n - 1];p++)
		if( summ < std::accumulate(p-1,p+2,0) )
			summ = ( std::accumulate(p-1,p+2,0) ),
			pg = p;

	std::cout << summ << " " << pg - door + 1 << std::endl;

	return 0;
}