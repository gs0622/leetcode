/*
https://leetcode.com/problems/range-sum-query-immutable/description/
https://leetcode.com/problems/range-sum-query-mutable/description/
*/
//#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
class NumArray2 {
 	vector<int> segs; 
 	vector<int> nums; 
	int build(int lo, int hi, int pos, vector<int>& nums){
		if (lo==hi) {
			segs[pos]=nums[lo];
			return segs[pos];
		}
		int mi=lo+(hi-lo)/2;
		segs[pos] = build(lo,mi, pos*2+1, nums) + build(mi+1, hi, pos*2+2, nums);
		return segs[pos];
	};
	int getSum(int qs, int qe, int ss, int se, int pos) {
		if (qs<=ss && qe>=se)	// overlap
			return segs[pos];
		if (qs>se || qe<ss)	// non-overlap
			return 0;
		int mi=ss+(se-ss)/2;
		return getSum(qs,qe,ss,mi,2*pos+1) + getSum(qs,qe,mi+1,se,2*pos+2);
	}
	void updateSum(int i, int diff, int ss, int se, int pos) {
		if (i<ss||i>se) return;	// non-overlap
		segs[pos]+=diff;	// overlap
		if (ss==se) return;
		int mi=ss+(se-ss)/2;
		updateSum(i,diff,ss,mi,2*pos+1);
		updateSum(i,diff,mi+1,se,2*pos+2);
	}
public:
	// O(n) time and space
	NumArray2(vector<int> &nums) {
		if (nums.empty()) return;
		int n=nums.size(), h=(int)ceil(log2(n));
		segs.resize(2*pow(2,h)-1, 0);
		build(0,n-1,0, nums);
		this->nums = nums;
	}
	// O(log(n)) time
	void update(int i, int val) {
		int diff = val-this->nums[i];
		this->nums[i]=val;
		updateSum(i, diff, 0, nums.size()-1, 0);
	}
	// O(log(n)) time
	int sumRange(int i, int j) {
		return getSum(i,j,0,nums.size()-1, 0);
	}
};
class NumArray {
 	vector<int> sum; 
public:
	NumArray(vector<int> &nums) {
		if (nums.size()==0) return;
		sum.push_back(nums[0]);
		for (int i=1; i<nums.size(); i++) sum.push_back(nums[i] + sum.back());
	}
	int sumRange(int i, int j) {
		return (i==0)? sum[j]: sum[j]-sum[i-1];
	}
};

int main(void) {
	std::vector<int> nums1{-2, 0, 3, -5, 2, -1};
	std::vector<int> nums2{-1,0,3,6};
	//NumArray numArray(nums1);
	NumArray2 s(nums2);
	cout << s.sumRange(0, 0) << endl;
	cout << s.sumRange(0, 3) << endl;
	cout << s.sumRange(1, 2) << endl;
	s.update(2,4);
	cout << s.sumRange(0, 3) << endl;
	//cout << numArray.sumRange(0, 5) << endl;
	//cout << numArray.sumRange(0, 0) << endl;
}
