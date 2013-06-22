#include <iostream>
#include <algorithm>

typedef unsigned int UINT;

int main()
{
	UINT n;
	std::cin >> n;
	UINT *correct_list = new UINT[n];
	for(size_t i=0;i<n;i++)
		std::cin >> correct_list[i];

	UINT m;
	UINT bdata;
	UINT count = 0;
	std::cin >> m;
	for(size_t i=0;i<m;i++)
	{
		std::cin >> bdata;
		if(std::binary_search(correct_list,correct_list+n,bdata))
			count++;
	}
	
	std::cout << count;

	return 0;
}