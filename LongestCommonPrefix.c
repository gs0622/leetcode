#include <stdio.h>
#include <string.h>
#include <limits.h>

char* longestCommonPrefix(char** strs, int strsSize)
{
	if (!strs || 0==strsSize) return;
	int rows, cols, c, i, len, min = INT_MAX, off;
	for (i=0; i<strsSize; i++) {
		len = strlen(strs[i]);
		if (len < min) min = len;
	}
	for (cols=0, off=0; cols<min; cols++) {
		c = strs[0][cols];
		for (rows=1; rows < strsSize; rows++)
			if (strs[rows][cols] != c) {
				off++;
				break;
			}
		if (rows != strsSize) break;
	}
	return strndup(strs[0]+off, cols-off);
}

int main(void)
{
	//char *strs[3] = {"foo223", "foo22312", "foo22342"};
	char *strs[3] = {"aoo223", "boo22312", "coo22342"};
	printf("%s\n", longestCommonPrefix((char**) &strs, 3));
}

