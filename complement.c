#include <stdio.h>
unsigned int complement(int num)
{
	unsigned int mask = ~0;
	while (num & mask) mask <<= 1;
	return ~mask & ~num;
}
int main(void)
{
	printf("%u\n", complement(5));
	printf("%u\n", complement(1));
}
