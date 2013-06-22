#include <iostream>

typedef unsigned int UINT;

struct RLE
{
	RLE() : count(0), prev(0), current(0) {};
	UINT count;
	UINT prev;
	UINT current;
};

int main()
{
	UINT n;
	UINT *a;

	std::cin >> n;
	a = new UINT[n];
	RLE pRLE;
	for(size_t i=0;i<n;i++)
		std::cin >> a[i];

	for(size_t i=0;i<n;i++)
	{
		pRLE.current = a[i];

		if(!pRLE.count)
			pRLE.prev = pRLE.current,
			pRLE.count = 1;

		else if(pRLE.prev == pRLE.current)
			pRLE.count++;
		else if(pRLE.prev != pRLE.current)
		{
			std::cout << pRLE.count << " " << pRLE.prev << " ";
			pRLE.count = 1;
			pRLE.prev = pRLE.current;
		}

		if( i == n-1 )
		{
			std::cout << pRLE.count << " " << pRLE.prev << " ";
		}
	}

	return 0;
}