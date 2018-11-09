#include <stdio.h>
int isValid(char* s)
{ 
	char stack[1024576], c;
	unsigned int n = 0;
	while (c = *s) {
		if (c == '(') stack[n++] = ')';
		else if (c == '{') stack[n++] = '}';
		else if (c == '[') stack[n++] = ']';
		else if (n == 0 || stack[--n] != c) return 0;
		s += 1;
	}
	return (0 == n);
}

int main(int argc, char **argv)
{
	if (argc < 2) return 0;
	printf("%s\n", argv[1]);
	printf("%d\n", isValid(argv[1]));
	return 0;
}
