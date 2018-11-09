#include <stdio.h>

int climbStairs(int n)
{
	int i, fn, fa = 1, fb = 2;
	if (n < 1) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	for (i = 2; i < n; i++) {
		fn = fa + fb;
		fa = fb, fb = fn;
	}
	return fn;
}
int main(void)
{
	printf("%d\n", climbStairs(1));
	printf("%d\n", climbStairs(2));
	printf("%d\n", climbStairs(3));
	printf("%d\n", climbStairs(10));
	return 0;
}
