#include <stdio.h>
#include <stdlib.h>
/* O(n^2) time */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize)
{
	int i, j;
	int *a = malloc(sizeof(int)*numsSize);
	struct node *p, *head = NULL;
	*returnSize = numsSize;
	for (i = 0; i < numsSize; i++) a[i] = -1;
	for (j=0; j < numsSize; j++) {
		for (i = j; i < 2*numsSize; i++) {
			if (nums[j] < nums[i%numsSize]) {
				a[j] = nums[i%numsSize];
				break;
			}
		}
	}
	return a;
}
#define ARR_SZ(a)	(sizeof(a)/sizeof(a[0]))
void test1(int *arr, int sz)
{
	int *p, i, ret;
	p = nextGreaterElements(arr, sz, &ret);
	for (i = 0; i < ret; i++)
		printf("%d ", p[i]);
	printf("\n");
	free(p);
}
int main(void)
{
	int a0[] = {1,2,1};
	int a1[] = {5,4,3,2,1};
	int a2[] = {1,5,3,6,8};
	test1(a0, ARR_SZ(a0));
	test1(a1, ARR_SZ(a1));
	test1(a2, ARR_SZ(a2));
	return 0;
}
