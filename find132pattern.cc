/* https://leetcode.com/problems/132-pattern/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// subsequence s1-s2-s3 w/ [s1]<[s3]<[s2]
	bool find132pattern(vector<int>& nums) {
		int s3=INT_MIN;
		stack<int> stk;
		for (int i=nums.size()-1; i>=0; --i) {
			if (nums[i]<s3)	return true;			// s1 candidate
			while (!stk.empty() && nums[i] > stk.top())	// s3 in stack
				s3 = stk.top(), stk.pop();		// track max s3
			stk.push(nums[i]);
		}
		return false;
	}
	// subsequence s1-s2-s3 w/ [s1]<[s3]<[s2]
	bool find132pattern1(vector<int>& nums) {
		int i, n=nums.size(), s3=INT_MIN;
		stack<int> s2;
		for (i=n-1; i>=0; --i) {			// backward tracking s2
			if (nums[i]<s3) return true;		// found s1
			while (!s2.empty() && nums[i]>s2.top()) // track max s3
				s3=s2.top(), s2.pop();
			s2.push(nums[i]);
		}
		return false;
	}
	// wrong because 132 pattern do not have to be consective elements
	bool find132pattern2(vector<int>& nums) {
		int j, n=nums.size();
		if (n<3) return false;
		for (j=1; j<n-1; ++j) {
			int ai,aj,ak;
			ai=nums[j-1], aj=nums[j], ak=nums[j+1];
			if (ai<ak && ak<aj) return true;
		}
		return false;
	}
};
int main(){
	Solution s;
	/*vector<int> nums1{1,2,3,4};
	cout << s.find132pattern(nums1) << endl;
	vector<int> nums2{3,1,4,2};
	cout << s.find132pattern(nums2) << endl;
	vector<int> nums3{-1, 3, 2, 0};
	cout << s.find132pattern(nums3) << endl;*/
	vector<int> nums4{3,5,0,3,4};
	cout << s.find132pattern(nums4) << endl;
}
