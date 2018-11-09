#include <ctype.h>
#include <stdio.h>
#include <string.h>
int isnum(char *s)
{
	int i = 0, j = strlen(s), isValid = 0;
	while (isblank(s[i])) i += 1; // trim heading space
	while (isblank(s[j-1])) j -= 1; // trim tailing space
	if (s[i] == '-' || s[i] == '+') i += 1;
	while (i < j && isdigit(s[i]))
		i++, isValid = 1;

	if (i < j && s[i] == '.') {
		i++;
		while (i < j && isdigit(s[i]))
			i++, isValid = 1;
	}
	return isValid && (i == j);
}
int main(void)
{
	int i;
	char *s[] = {
		"0", "0.1", "abc", "1 1", "0xff", "1e10"
	};
	for (i = 0; i < sizeof(s)/sizeof(char *); i += 1) {
		printf("%-10s: %s\n", s[i], isnum(s[i])? "true": "false");
	}
	return 0;
}
