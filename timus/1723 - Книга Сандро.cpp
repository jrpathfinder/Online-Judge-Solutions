#include <iostream>
#include <fstream>
#include <map>

#define NBUF 64

int main()
{
	char	*word;
	char	buf[NBUF];
	int		lword;

#ifndef _DEBUG
	std::cin.getline(buf,NBUF);
#else
	std::ifstream fin("input.txt");
	fin.getline(buf,NBUF);
	fin.close();
#endif
	lword = strlen(buf);
	word = new char[lword + 1];
	strcpy(word,buf);
	word[lword] = '\0';
	
	std::map<char,int> dict;
	for(int i=0;i<lword;i++)
		dict[word[i]]++;

	char	des = 'a';
#ifndef _DEBUG
	for(auto p = dict.begin();p!=dict.end();p++)
		if(p->second > dict[des])
			des = p->first;
#else
	for(auto p : dict)
		if(p.second > dict[des])
			des = p.first;
#endif
		

	std::cout << des << std::endl;

	return 0;
}