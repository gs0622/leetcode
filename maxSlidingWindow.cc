/* https://leetcode.com/problems/sliding-window-maximum/description/
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Note:
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
*/
#include <bits/stdc++.h>
using namespace std;
class Monoqueue {
  deque<pair<int,int>> dq;
public:
  void push(int val) {
    int cnt=0;
    while (dq.size() && val > dq.back().first)
      cnt+=dq.back().second, dq.pop_back();
    dq.push_back({val,cnt});
  }
  void pop() {
    if (dq.front().second > 0) dq.front().second--;
    else dq.pop_front();
  }
  int top() { return dq.front().first; }
};
class Solution2 {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n=nums.size(), i;
    Monoqueue mq;
    for (int i=0; i<k-1; ++i)
      mq.push(nums[i]);
    vector<int> res;
    while (i<k) {
      mq.push(nums[i]); // k window
      res.push_back(mq.top());
      mq.pop(); // down to k-1 window
    }
    return res;
  }
};
class Solution1 {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n=nums.size();
    deque<int> dq;
    vector<int> res;
    for (int i=0;i<n;++i) {
      if (dq.size() && dq.front()==i-k)
        dq.pop_front();

      while (dq.size() && nums[dq.back()]<nums[i])
        dq.pop_back();

      dq.push_back(i);

      if (i>=k-1)
        res.push_back(nums[dq.back()]);
    }
    return res;
  }
};
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n=nums.size();
    vector<int> res;
    for (int i=0;i<n;++i) {
      if (i>=k-1) {
        int val=nums[i];
        for (int j=i-k; j<i;++j)
          val=max(val,nums[j]);
        res.push_back(val);
      }
    }
    return res;
  }
};
int main(){}
