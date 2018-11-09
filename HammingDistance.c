#include <stdio.h>
unsigned int HammingWeight(unsigned int i)
{
	unsigned int cnt = 0;
	while ((i&1)==1) cnt += 1, i >>= 1;
	return cnt;
}
unsigned int HammingDistance(unsigned int x, unsigned int y)
{
	unsigned int xor = x^y;
	return HammingWeight(xor);
}
int main(void)
{
	printf("%d\n", HammingDistance(1,4));
}

