/* https://leetcode.com/problems/max-consecutive-ones/description/

- Max Consecutive Ones

  Given a binary array, find the maximum number of consecutive 1s in this array.

- Max Consecutive Ones II
Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.

Example 1:

Input: [1,0,1,1,0]
Output: 4
Explanation: Flip the first zero will get the the maximum number of consecutive 1s.
    After flipping, the maximum number of consecutive 1s is 4.

Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
 
Follow up:
What if the input numbers come in one by one as an infinite stream?
In other words, you can't store all numbers coming from the stream as it's too large to hold in memory. Could you solve it efficiently?
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(n) for Max Consecutive Ones II
	int findMaxConsecutiveOnes1(vector<int>& nums, int k=1) {
		int res=0, left=0;
		queue<int> q;
		for (int i=0; i<nums.size(); ++i) {
			if (nums[i]==0) q.push(i);
			if (q.size()>k)
				left=q.front()+1, q.pop();
			res=max(res, i-left+1);
		}
		return res;
	}
	// O(n) for Max Consecutive Ones II
	int findMaxConsecutiveOnes(vector<int>& nums, int k=1) {
		int res=0, left=0, zeros=0;
		for (int i=0; i<nums.size(); ++i) {
			if (nums[i]==0) ++zeros;
			while (zeros>k) {
				if (nums[left++]==0)
					--zeros;
			}
			res=max(res, i-left+1);		// think why+1? b/c left is included, i.e. [left...0...i]
		}
		return res;
	}
	// O(n) for Max Consecutive Ones
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int res=0,cnt=0;
		for (auto n: nums) {
			if (n==0) cnt=0;
			else ++cnt;
			res=max(res,cnt);
		}
		return res;
    }
    
};
int main(){
	Solution s;
	vector<int> nums{1,0,1,1,0};
	cout << s.findMaxConsecutiveOnes1(nums,1) << endl;
	cout << s.findMaxConsecutiveOnes1(nums,2) << endl;
}
