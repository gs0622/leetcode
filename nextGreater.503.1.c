#include <stdio.h>
#include <stdlib.h>
/* O(n) time */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize)
{
	static int stack[10000];
	int st = -1; // stack top
	int i, j;
	int *a = malloc(sizeof(int)*numsSize);
	struct node *p, *head = NULL;
	*returnSize = numsSize;
	for (i = 0; i < numsSize; i++) a[i] = -1;
	for (i = 0; i < 2*numsSize; i++) {
		int val = nums[i % numsSize];
		while (st >= 0 && val > nums[stack[st]])
			a[stack[st--]] = i; // pop index to returning array
		if (i < numsSize) stack[++st] = i; // push index
	}
	return a;
}
#define ARR_SZ(a)	(sizeof(a)/sizeof(a[0]))
void test(int *arr, int sz)
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
	test(a0, ARR_SZ(a0));
	test(a1, ARR_SZ(a1));
	test(a2, ARR_SZ(a2));
	return 0;
}
