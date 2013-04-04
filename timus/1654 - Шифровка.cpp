#include <iostream>
#include <fstream>
#include <stack>

int main()
{
	char	word[200001];
	
#ifndef _DEBUG
	std::cin >> word;
#else
	std::ifstream fin("../input.txt");
	fin >> word;
	fin.close();
#endif
	int	lword;
	lword = strlen(word);
	word[lword] = '\0';	

	std::stack<char> dict;
	for(int i=0;i<lword;i++)
		if(dict.empty()) dict.push(word[i]);
		else if( dict.top() == word[i] ) dict.pop();
		else dict.push(word[i]);

	lword = dict.size();
	memset(word,0,sizeof(word));
	for(int i=0;i<lword;i++)
		word[lword - 1 - i] = dict.top(),
		dict.pop();

	std::cout << word << std::endl;

	return 0;
}