#include <stdio.h>
#include <stdlib.h>

static int cmp(const void *p, const void *q)
{
	int i = *((const int *)p), j = *((const int *)q);
	return (i-j);
}

int containsDuplicate(int* nums, int numsSize)
{
	int i, isdup = 0;
	qsort(nums, numsSize, sizeof(int), cmp);
	for (i = 1; i < numsSize; i++) {
		if (nums[i-1] == nums[i]) {
			isdup = 1;
			break;
		}
	}
	return isdup;
}

int main(void)
{
	int a0[] = {1, 2, 3, 4, 5};
	int a1[] = {1, 2, 3, 4, 5, 1};
	printf("%d\n", containsDuplicate(a0, sizeof(a0)/sizeof(int)));
	printf("%d\n", containsDuplicate(a1, sizeof(a1)/sizeof(int)));
	return 0;
}
