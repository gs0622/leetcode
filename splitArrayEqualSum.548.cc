/* 548. Split Array with Equal Sum
Given an array with n integers, you need to find if there are triplets (i, j, k) which satisfies following conditions:

0 < i, i + 1 < j, j + 1 < k < n - 1
Sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1) should be equal.
where we define that subarray (L, R) represents a slice of the original array starting from the element indexed L to the element indexed R.

Example:
Input: [1,2,1,2,1,2,1]
Output: True
Explanation:
i = 1, j = 3, k = 5. 
sum(0, i - 1) = sum(0, 0) = 1
sum(i + 1, j - 1) = sum(2, 2) = 1
sum(j + 1, k - 1) = sum(4, 4) = 1
sum(k + 1, n - 1) = sum(6, 6) = 1
Note:

1 <= n <= 2000.
Elements in the given array will be in range [-1,000,000, 1,000,000].
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool splitArray2(vector<int>& nums) {
		int i,j,k,n=nums.size();
		vector<int> sums(nums);
		for (int i=1; i<n; ++i)
			sums[i]+=sums[i-1];
		for (i=1; i<=n-5; ++i) {
			if (i!=1 && nums[i]==0 && nums[i-1]==0)
				continue;
			for (j=i+2; j<=n-3; ++j) {
				if (sums[i-1]!=sums[j-1]-sums[i])
					continue;
				for (int k=j+2; k<=n-1; ++k) {
					int sumC=sums[k-1]-sums[j], sumD=sums[n-1]-sums[k];
					if (sumC==sumD && sumC==sums[i-1])
						return true;
				}
			}
		}
		return false;
	}
	bool splitArray1(vector<int>& nums) {
		int i,j,k,n=nums.size();
		vector<int> sums(nums);			// good one, think about it
		for (int i=1; i<n; ++i)
			sums[i]+=sums[i-1];		// sums[i]==nums[i] initially

		for (j=3; j<n-3; ++j) {			// fix j
			unordered_set<int> s;
			for (i=1; i<j-1; ++i)		  // i floating, [ <-..i..->.. j ...]
				if (sums[i-1] == sums[j-1]-sums[i])	// sumA == sumB
					s.insert(sums[i-1]);
			for (k=j+1; k<n-1; ++k) {	// k floating
				int sumC = sums[k-1]-sums[j], sumD = sums[n-1]-sums[k];
				if (sumC = sumD && s.count(sumC))
					return true;
			}
		}
		return false;

	}
	// O(n^3) brute force
	bool splitArray(vector<int>& nums) {
		int i,j,k,n=nums.size();
		vector<int> sums(n);
		sums[0]=nums[0];
		for (i=1; i<n; ++i)
			sums[i]=sums[i-1]+nums[i];

		for (i=1; i<n; ++i) {       // i,j,k are split points
			for (j=i+2; j<n; ++j) {
				for (k=j+2; k<n; ++k) {
          // exclude elements i, j, and k
					int A = sums[i-1], B = sums[j-1]-sums[i], C = sums[k-1]-sums[j], D = sums[n-1]-sums[k];
					if (A == B && A == C && A == D)
							return true;
				}
			}
		}
		return false;
	}
};
int main(){
	Solution s;
	vector<int> nums{1,2,1,2,1,2,1};
	cout << s.splitArray(nums) << ": " << s.splitArray1(nums) << ": " << s.splitArray2(nums) << endl;
}
