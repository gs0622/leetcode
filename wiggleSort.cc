/*
Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].
*/
#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
  void wiggleSort(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    for (int i=2; i<nums.size(); i+=2)  // see thru the data: swap the even (even+1)
      swap(nums[i],nums[i-1]);
  }
};
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		vector<int> tmp(nums);
		sort(begin(tmp), end(tmp));
		for (int i=nums.size()-1, j=0, k=i/2+1; i>=0; --i)
			nums[i]=tmp[i&1? k++: j++];
	}
};
int main(){
	Solution2 s;
	vector<int> A1{1,5,1,1,6,4};
	s.wiggleSort(A1);
	for (auto n: A1) cout << n << ' ';
	cout << endl;
	vector<int> A2{1,3,2,2,3,1};
	s.wiggleSort(A2);
	for (auto n: A2) cout << n << ' ';
	cout << endl;
	vector<int> A3{3, 5, 2, 1, 6, 4};
	s.wiggleSort(A3);
	for (auto n: A3) cout << n << ' ';
	cout << endl;
}
