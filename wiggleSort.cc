/**/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	void wiggleSort1(vector<int>& nums) {
		vector<int> tmp(nums);
		sort(begin(tmp), end(tmp));
		for (int i=nums.size()-1, j=0, k=i/2+1; i>=0; --i)
			nums[i]=tmp[i&1? k++: j++];
	}
	void wiggleSort(vector<int>& nums) {
		if (nums.empty()) return;
		int n=nums.size();
		// s1: find median
		auto midptr=begin(nums)+n/2;
		nth_element(begin(nums), midptr, end(nums));
		int mid=*midptr;

		// Index-rewiring
		#define A(i) nums[(1+2*(i)) % (n|1)]

		// 3-way-partition-to-wiggly in O(n) time with O(1) space.
		int i=0, j=0, k=n-1; // it, j, gt
		while (j <= k) {
			if (A(j) > mid)		swap(A(i++), A(j++));
			else if (A(j) < mid)	swap(A(j), A(k--));
			else			j++;
		}
	}
};
int main(){
	Solution s;
	vector<int> nums1{1,5,1,1,6,4};
	vector<int> nums2{1,3,2,2,3,1};
	s.wiggleSort1(nums1);
	for (auto n: nums1) cout << n << ' ';
	cout << endl;
	s.wiggleSort1(nums2);
	for (auto n: nums2) cout << n << ' ';
	cout << endl;
}
