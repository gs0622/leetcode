#include <climits>
#include <iostream>
#include <vector>
using namespace std;
// Q: whether or not there are dup keys?
// Q: what about input array empty?
class Solution {
public:
	// O(lg(n)) binary search, tackle dup keys
	int findMin(vector<int>& nums) {
		int mi, lo=0, hi=nums.size()-1;
		while (lo<hi && nums[lo] >= nums[hi]) { // in case dup when [lo]==[hi]
			mi = lo+(hi-lo)/2;
			if (nums[mi] > nums[lo]) { // aka. [mi] > [hi]
				lo = mi+1;
			} else if (nums[mi] < nums[lo]){
				hi = mi;
			} else ++lo; // equal, [mi]==[lo]
		}
		return nums[lo];
	}
	// O(lg(n)) binary search, buggy in test5 w/ dup keys
	int findMin1(vector<int>& nums) {
		int mi, lo=0, hi=nums.size()-1;
		while (nums[lo] > nums[hi]) {
			mi = lo+(hi-lo)/2;
			if (nums[mi] >= nums[lo]) {	// or [mi] > [hi]
				lo = mi+1;
			} else {
				hi = mi;
			}
		}
		//lo==hi
		return nums[lo];
	}
	int findMin2(vector<int>& nums) {
		int min = INT_MAX;
		for (auto v: nums) {
			if (v < min)
				min = v;
		}
		return min;
	}
};
void test();
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
int main(){
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
}
void test(vector<int> nums){
	Solution s;
	cout << s.findMin(nums) << ": ";
	cout << s.findMin2(nums) << endl;
}
void test1(){
	vector<int> nums{4,5,6,7,0,1,2};
	test(nums);
}
void test2(){
	vector<int> nums{5,6,7,0,1,2,3,4};
	test(nums);
}
void test3(){
	vector<int> nums{2,1};
	test(nums);
}
void test4(){
	vector<int> nums{1,2};
	test(nums);
}
void test5(){
	vector<int> nums{1, 1, 1, 0, 1};
	test(nums);
}
void test6(){
	vector<int> nums{1};
	test(nums);
}
void test7(){
	vector<int> nums{10,1,10,10,10};
	test(nums);
}
