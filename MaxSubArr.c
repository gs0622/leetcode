#include <stdio.h>
#include <limits.h>
static int max(int a, int b)
{
	return (a>b)? a: b;
}
int maxSubArray(int* nums, int numsSize)
{
	if (1 == numsSize) return nums[0];
	int i, c = INT_MIN , s = INT_MIN;
	for (i = 0; i < numsSize; i++) {
		c = max(nums[i], (c>0)? c+nums[i]: c);
		s = max(c, s);
	}
	return s;
}

int main(void)
{
	int a0[] = {-2,1,-3,4,-1,2,1,-5,4};
	int a1[] = {-1};
	int a2[] = {-2,-1};
	printf("%d\n", maxSubArray(a0, sizeof(a0)/sizeof(int)));
	printf("%d\n", maxSubArray(a1, sizeof(a1)/sizeof(int)));
	printf("%d\n", maxSubArray(a2, sizeof(a2)/sizeof(int)));
	return 0;
}
