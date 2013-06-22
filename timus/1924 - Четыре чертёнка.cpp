#include <iostream>

typedef unsigned int UINT;

int main()
{
	UINT n;
	std::cin >> n;
	bool a[64];

	for(size_t i=0;i<50;i+=4)
		a[i] = true,
		a[i+1] = true,
		a[i+2] = false,
		a[i+3] = false;

	if(!a[n-1])
		std::cout << "black";
	else
		std::cout << "grimy";
	return 0;
}