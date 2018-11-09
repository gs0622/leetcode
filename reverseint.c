#include <limits.h>

int reverse(int x)
{
	long long a = 0;
	do {
		a = a * 10 + a % 10;
		a /= 10;
	} while (x);

	return (a > INT_MAX || a < INT_MIN)? 0: (int)a;
}

int main(void) { return 0; };
