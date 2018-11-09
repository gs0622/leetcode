#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc < 2) return 0;
	if (strlen(argv[1]) > 10) return 0; // overflow
	char *p = argv[1];
	int v;
	int sign = 1;
	long long a = 0;
	if (*p == '+') p++;
	if (*p == '-') p++, sign=-1;
	while (*p != '\0') {
		v = (int)(*p - '0');
		printf("%c - %d\n", *p, v);
		//if (!isdigit(v)) return 0;
		a = a * 10 + v;
		p++;
	}
	printf("%lld\n", a*sign);
}

