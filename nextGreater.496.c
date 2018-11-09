#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/* O(nm) time */
int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize)
{
	int i, j;
	int sz = sizeof(int)*findNumsSize;
	int *arr = malloc(sz);
	*returnSize = findNumsSize;
	for (i = 0; i < findNumsSize; i++) {
		for (j = 0; j < numsSize; j++) {
			if (nums[j] == findNums[i]) {
				j++;
				while (j < numsSize && nums[j] <= findNums[i])
					j++;
				arr[i] = (j < numsSize)? nums[j]: -1;
			}
		}
	}
	return arr;
}
#define ARR_SZ(a)	(sizeof(a)/sizeof(a[0]))
int main(void)
{
	//int n1[] = {4,1,2}, n2[] = {1,3,4,2};
	int n1[] = {2,4}, n2[] = {1,2,3,4};
	int i, *arr, ret;
	arr = nextGreaterElement(n1, ARR_SZ(n1), n2, ARR_SZ(n2), &ret);
	for (i = 0; i < ret; i++)
		printf("%d ", arr[i]);
	printf("\n");
	free(arr);
	return 0;
}
