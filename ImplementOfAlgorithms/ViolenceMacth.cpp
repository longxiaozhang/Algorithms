#include <stdlib.h>
#include <iostream>
#include <string.h>
#define ERROR_MATCH 0

using namespace std;

template<class T>
size_t violentMatch(const T *s,size_t ssize,const T *p,size_t psize)
{
	if (ssize < psize || NULL == s || NULL == p) {
		return ERROR_MATCH;
	}
	size_t i,j = 0;
	for(i = 0;ssize -i > psize;++i,j=0) {
		while ((*(s+i) == *(p+j)) && (j < psize)) {
			++i,++j;
			continue ;
		}

		i = i - j;
		if ( j == psize)
			return i+1;		
	}

	return ERROR_MATCH;
}

int main(int argc, char *argv[])
{
	size_t position = 0;

	char s[] = "abcdefasdc";
	char p[] = "efa";

	position = violentMatch(s,strlen(s),p,strlen(p));

	cout << position<<endl; 
	return true;
}
