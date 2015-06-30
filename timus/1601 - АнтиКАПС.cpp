#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::string msg;

#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif
	
	bool first = true;
	char p;
	while( (p = getchar()) != EOF ) {
		if(p == '.' || p == '!' || p == '?'){
			putchar(p);
			first = true;
		} else {
			if(p >= 'a' && p <= 'z'){
				if(first) putchar(p - 'a' + 'A');
				else putchar(p);
				first = false;
			} else if(p >= 'A' && p <= 'Z'){
				if(first) putchar(p);
				else putchar(p - 'A' + 'a');
				first = false;
			} else putchar(p);
		}
	}

	return 0;
}