#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <iostream>
using namespace std;
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/* O(n) time */
int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize)
{
	static int stack[1000];
	int st = -1; // stack top pointer
	int i, j;
	int sz = sizeof(int)*findNumsSize;
	int *arr = (int *)malloc(sz);
	std::unordered_map<int, int> m;
	*returnSize = findNumsSize;
	for (i = 0; i < findNumsSize; i++) arr[i] = -1;
	for (i = 0, j = 0; i < numsSize; i++) {
		while (st >= 0 && nums[i] > stack[st]) { // peek
			m[stack[st--]] = nums[i];
		}
		stack[++st] = nums[i];
	}
	for (auto x: m) {
		//std::cout << "m: " << x.first << " < " << x.second << endl;
	}
	for (i = 0; i < findNumsSize; i++) {
		auto it = m.find(findNums[i]);
		if (it != m.end()) {
			//std::cout << "f: " << it->first << " < " << it->second << endl;
			arr[i] = it->second;
		}
	}
	return arr;
}
#define ARR_SZ(a)	(sizeof(a)/sizeof(a[0]))
void test(int *a1, int s1, int *a2, int s2)
{
	int i, *arr, ret;
	arr = nextGreaterElement(a1, s1, a2, s2, &ret);
	for (i = 0; i < ret; i++)
		printf("%d ", arr[i]);
	printf("\n");
	free(arr);
}
int main(void)
{
	int n1[] = {4,1,2}, n2[] = {1,3,4,2};
	int n3[] = {2,4}, n4[] = {1,2,3,4};
	test(n1, ARR_SZ(n1), n2, ARR_SZ(n2));
	test(n3, ARR_SZ(n3), n4, ARR_SZ(n4));
	return 0;
}
