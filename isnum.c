#include <stdio.h>
#include <string.h>
int isnum(char *s)
{
	int i = 0, j = strlen(s) - 1;
	while (isblank(s[i])) i += 1; // trim heading space
	while (isblank(s[j])) j -= 1; // trim tailing space
	if (s[i] == '-' || s[i] == '+') i += 1;
	if (s[j] == '.') goto out;
	while (i <= j) {
		int dot = 0;
		if (isdigit(s[i]) && isdigit(s[j])) {
			i += 1, j -= 1;
			continue;
		}
		if (s[i] == '.') {
			dot += 1;
			i += 1;
			continue;
		}
		if (s[j] == '.') {
			dot += 1;
			j -= 1;
			continue;
		}
		goto out;
	}
	return 1; // true
out:
	return 0; // false
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
