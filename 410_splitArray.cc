/* https://leetcode.com/problems/split-array-largest-sum/description/
 410. Split Array Largest Sum

Given an array which consists of non-negative integers and an integer m,
you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

Note:
If n is the length of array, assume the following constraints are satisfied:

1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)

*/
#include <bits/stdc++.h>
using namespace std;

class Solution2 {
public:
	int splitArray(vector<int>& nums, int m) {
    int sum=accumulate(nums.begin(), nums.end(), 0);
    if (m==1) return sum;
    function<bool(int)> valid=[&](int target) {
      int cnt=1, csum=0;
      for (int n: nums) {
        csum+=n;
        if (csum>target) {
          ++cnt, csum=n;
          if (cnt>m) return false;  // target is too small
        }
      }
      return true;  // target is valid
    };
    int lo=*max_element(nums.begin(), nums.end()), hi=sum;  // search space of the largest sum
    while (lo<hi) {
      int mi=lo+(hi-lo)/2;
      if (valid(mi)) hi=mi;
      else lo=mi+1;
    }
    return lo;
  }
};
class Solution {
public:
	int splitArray(vector<int>& nums, int m) {
		int sum = accumulate(begin(nums), end(nums), 0);
		int max = *max_element(begin(nums), end(nums));
		if (m==1) return sum;

		function<bool(int,int)> valid = [&](int target, int m) {
			int cnt=1, sum=0;
			for (int n: nums) {
				sum+=n;			// partial sum
				if (sum>target) {	// partial > split sum, cnt+=1
					sum=n,++cnt;    // new sum starts from current n
					if (cnt>m) return false;	// target too small, need more than m splits
				}
			}
			return true;	// m split capable in terms of target sum
		};
		int lo=max, hi=sum;
		//int lo=nums[0], hi=sum;	// wrong: description requires a minimized largest sum, see 2nd test case
		while (lo<=hi) {
			int mi=lo+(hi-lo)/2;	// target partial sum
			if (valid(mi, m))	// transform mi into m split capable false/true search space
				hi=mi-1;
			else
				lo=mi+1;
		}
		return lo;
	}
};
int main(){
	Solution2 s;
	vector<int> nums1{7,2,5,10,8};
	cout << s.splitArray(nums1, 2) << endl;
	vector<int> nums2{1,2147483647};
	cout << s.splitArray(nums2, 2) << endl;
}
