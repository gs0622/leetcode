#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;
struct triple { int x, y, z;};

int** threeSum(int* nums, int numsSize, int* returnSize)
{
	int i = numsSize, j, a = 0, sum;
	//int *ans = malloc(sizeof(int)*i*(i-1)*(i-2)/6);
	std::unordered_map<int, int> m;
	std::unordered_map<int, struct triple> n;
	triple *ans = NULL;
	for (i=0; i<numsSize; i++) m[nums[i]] = i;
	for (i=0; i<numsSize-1; i++)
		for (j=i+1; j<numsSize; j++) {
			sum = nums[i] + nums[j];
			auto it = m.find(-sum);
			if (it != m.end()) {
				triple t = {nums[i], nums[j], -sum};
				//printf("%d %d %d\n", t.x, t.y, t.z);
				printf("%d %d i=%d j=%d\n", it->first, it->second, i, j);
				if ((i!= it->second) && (j!=it->second)) {
					printf("%d %d %d\n", t.x, t.y, t.z);
				}
			}
	}		
}

int main(void)
{
	int arr[] = {-1, 0, 1, 2, -1, -4};
	sort(arr, arr+(sizeof(arr)/sizeof(int)));
	for (int i=0; i<sizeof(arr)/sizeof(int); i++) printf("%d ", arr[i]);
	printf("\n");
	threeSum(arr, sizeof(arr)/sizeof(int), NULL);
}

