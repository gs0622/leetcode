#include <stdio.h>
unsigned int NumberOfSetBits(unsigned int i)
{
#if 1
	unsigned int cnt = 0;
	while (i) cnt += (i&1)? 1:0, i >>= 1;
	return cnt;
#else
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
#endif
}

int main(void)
{
	unsigned int arr[3] = {3, 5, 15};
	printf("%d\n", NumberOfSetBits(arr[0]));
	printf("%d\n", NumberOfSetBits(arr[1]));
	printf("%d\n", NumberOfSetBits(arr[2]));
}

