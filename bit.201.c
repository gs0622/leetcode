#include <stdio.h>
int rangeBitwiseAnd2(int m, int n) {
	int ans = m;
	for (int i=m; i<=n; ++i) ans &= i;
	return ans;
}
int rangeBitwiseAnd(int m, int n)
{
	return (n > m)? rangeBitwiseAnd(m/2, n/2) << 1: m;
}

int main(void)
{
	printf("0x%x 0x%x\n", rangeBitwiseAnd(5,7), rangeBitwiseAnd2(5,7));
	printf("0x%x 0x%x\n", rangeBitwiseAnd(1,3), rangeBitwiseAnd2(1,3));
	printf("0x%x 0x%x\n", rangeBitwiseAnd(1000,1001), rangeBitwiseAnd2(1000,1001));
	return 0;
}
