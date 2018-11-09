#include <stdio.h>
#include <string.h>
static void _reverse(char *s, int i, int j)
{
	while (i < j) {
		s[i] ^= s[j], s[j] ^= s[i], s[i] ^= s[j]; // i!=j
		i++, j--;
	}
}
char* reverseStr(char* s, int k)
{
	int i, len = strlen(s);
	for (i = 0; i < len; i+=k*2) {
		int j = (i+k-1);
		if (j >= len) j = len-1;
		_reverse(s, i, j);
	}
	return s;
}
int main(void)
{
	char s[] = "abcdefg";
	printf("%s\n", reverseStr(s, 2));
	return 0;
}
