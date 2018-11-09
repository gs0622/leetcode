#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
static char stack[10002];
char* removeKdigits(char *str, int k)
{
	int i = -1; // stack index
	int sb = 0; // stack bottom
	int len = strlen(str);
	int keep = len - k;
	int j = 0;
	if (0 == keep) {
		stack[0] = '0';
		stack[1] = '\0';
		return stack;
	}
	memset(stack, 0, 10002);
	while (j < len) {
		while (k > 0 && i >= 0 && stack[i] > str[j]) {
			stack[i--] = 0;
			k--;
		}
		stack[++i] = str[j++];
	}
	stack[keep] = '\0';
	for (j = 0; j < i; j++) { // trim leading '0'
		if ('0' == stack[j]) {
			stack[j] = 0;
			sb++;
		} else
			break;
	}
	return &stack[sb];
}
void *test(char *str, int k)
{
	printf("%s\n", removeKdigits(str, k));
}
int main(void)
{
	char s0[] = "1432219";
	char s1[] = "10200";
	char s2[] = "10";
	char s3[] = "9";
	char s4[] = "112";
	char s5[] = "1234567890";
	test(s0, 3);
	test(s1, 1);
	test(s2, 2);
	test(s3, 1);
	test(s4, 1);
	test(s5, 9);
	return 0;
}
