/* https://leetcode.com/problems/minimum-size-subarray-sum/description/
hint: two pointers
*/

#include <climits>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
	int larger_than(vector<int>& arr, int lo, int hi, int val) {
		while (lo < hi) {
			int mi = lo+(hi-lo)/2;
			// cut off those elems <= val
			if (arr[mi] <= val) lo=mi+1;
			else hi=mi;
		}
		//cout << lo <<"-"<< hi << endl;
		return (arr[lo] > val)? lo: -1;
	}
public:
	// Brute-force
	int minSubArrayLen3(int s, vector<int>& nums) {
		int i, j, n=nums.size(), res=INT_MAX;
		for (i=0; i<n; ++i) {	// start
			int sum=0;
			for (j=i; j<n; ++j) {
				sum+=nums[j];
				if (sum>=s) {
					res = min(res, j-i+1);
					break;
				}
			}

		}
		return res==INT_MAX? 0: res;
	}
	// O(nlog(n))
	int minSubArrayLen2(int s, vector<int>& nums) {
		int i, sz = nums.size(), ans = INT_MAX;
		vector<int> sums(sz, 0);
		for (i=1; i<sz; ++i) sums[i]+=nums[i]+sums[i-1];
		for (i=0; i<sz; ++i) {
			if (sums[i] >= s) {
				//int j = larger_than(sums, 0, i, sums[i]-s);
				//cout << i << ": " << j << endl;
				//if (j!=-1) ans = std::min(ans, i-j+1);
				auto it = lower_bound(sums.begin(), sums.begin()+i, sums[i]-s);
				if (it!=sums.begin()+i) ans = min(ans, (int)distance(it, sums.begin()+i));
			}
		}
		return ans;
	}
	// O(n), two pointers, greedy?
	int minSubArrayLen1(int s, vector<int>& nums) {
		int sum=0, left=0, ans = INT_MAX;
		for (int i=0; i<nums.size(); ++i) {
			sum+=nums[i];
			while (sum>=s) {
				ans = min(ans, i-left+1);
				sum -= nums[left++];
			}
		}
		return (ans==INT_MAX)? 0: ans;
	}
	// two pointers
	int minSubArrayLen(int s, vector<int>& nums) {
		int sum=0, right=0, left=0;
		int sz=nums.size(), ans = INT_MAX;
		while (right < sz) {
			// always forward right until sum >= s
			do {
				sum+=nums[right++];
			} while (sum < s && right < sz);

			// forward left maintain sum >= s
			while (left < right && (sum - nums[left]>=s))
				sum-=nums[left++];

			if (sum >= s) ans = std::min(ans, right-left);
		}
		return (ans == INT_MAX)? 0: ans;
	}
};
int main(){
	vector<int> nums {2,3,1,2,4,3};
	Solution s;
	cout << s.minSubArrayLen(7, nums) << ": " << s.minSubArrayLen2(7, nums) << endl;
}

