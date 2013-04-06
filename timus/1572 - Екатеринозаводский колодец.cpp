// 1572. Екатеринозаводский колодец
// 0.031	s
// 212		КБ

#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <numeric>

#define M_PI       3.14159265358979323846

enum TypeHatch
{
	CIRCLE = 1,
	SQUARE,
	TRIANGLE
};

typedef	int idTypeHatch;

struct Hatch
{
	idTypeHatch	type;
	int			leught;
};

std::istream& operator>>(std::istream& is, Hatch &p)
{
	is >>  p.type >> p.leught;
	return is;
}


double	maxLeught(const Hatch& src)
{
	switch (src.type)
	{
	case CIRCLE:
		return 2.0 * src.leught;
	case SQUARE:
		return src.leught * sqrt(2.0);
	case TRIANGLE:
		return src.leught;
	default:
		break;
	}
}

double	minLeught(const Hatch& obj)
{
	switch (obj.type)
	{
	case CIRCLE:
		return 2.0 * obj.leught;
	case SQUARE:
		return obj.leught;
	case TRIANGLE:
		return obj.leught * sin(M_PI / 3.0);
	default:
		break;
	}
}

bool isRight(double max, const Hatch& obj)
{
	return max >= minLeught(obj);
}

int main()
{
	Hatch		well;
	int			n;
	Hatch		stuff[101];
#ifndef _DEBUG
	std::cin	>> well >> n;
	for(auto i=0;i<n;i++)
		std::cin >> stuff[i];
#else
	std::ifstream fin("input.txt");
	fin >> well >> n;
	for(auto i=0;i<n;i++)
		fin >> stuff[i];
	fin.close();
#endif

	int nCount = 0;
	double dmaxLeught = maxLeught(well);
	for(int i=0;i<n;i++)
		if( isRight(dmaxLeught, stuff[i]) )
			nCount++;

	std::cout << nCount << std::endl;

	return 0;
}