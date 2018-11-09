#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
static int isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return 1;
	return 0;
}
int myatoi(char *s)
{
	char *p = s;
	long long sign = 1, v = 0;
	if (*p == '-') sign = -1, p += 1;
	while (!isdigit(*p))
		p += 1;
	if (!*p)
		goto no_conversion;
	while (*p) {
		if (!isdigit(*p))
			break;
		v = v * 10 + (*p - '0');
		p += 1;
		if (sign == 1 && v >= INT_MAX) break;
		if (sign == -1 && v >= (-1) * (long long)INT_MIN) break;
	}
	v *= sign;
	if (v >= INT_MAX)
		return INT_MAX;
	else if (v <= INT_MIN)
		return INT_MIN;
	else return (int)v;

no_conversion:
	return 0;
}
int main(void)
{
	int i;
	char *s[7] = {
		"1",
		"-1",
		"-2147483649",
		"2147483648",
		" 100 ",
		"-999a",
		"+2",
	};
	for (i = 0; i < 7; i += 1) {
		printf("%11d: %11d\n", atoi(s[i]), myatoi(s[i]));
	}
	return 0;
}
