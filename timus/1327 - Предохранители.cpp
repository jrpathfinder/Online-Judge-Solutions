#include <iostream>

typedef unsigned int UINT;

int main()
{
	UINT a,b;
	UINT count = 0;
	std::cin >> a >> b;
	
	for(size_t i=a;i<=b;i++)
		if( (i % 2) )
			count++;

	std::cout << count;

	return 0;
}