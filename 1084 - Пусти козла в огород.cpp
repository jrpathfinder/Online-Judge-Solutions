#include <iostream>
#include <math.h>
#include <iomanip>
#define PI 3.14159265358979323846

using namespace std;

int main()
{
	double L, R;
	cin >> L >> R;

	cout<<setiosflags(ios::fixed)<<setprecision(3)<<endl;

	if(L >= 2*R)
		cout << PI * R * R << endl;

	else if(R >= L/2.0*sqrt(2.0))
		cout << L*L << endl;

	else
		cout << (PI * R * R) - 4.0 * ( 1.0/2.0 * R * R * ( 2 * acos( (double)L / R / 2.0 ) - sin( 2 * acos( (double)L / R / 2.0 ) ) ) ) << endl;

	return 0;
}