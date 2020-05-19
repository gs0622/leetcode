/* https://leetcode.com/problems/next-greater-element-i/description/

You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
  vector<int> nextGreaterElements(vector<int>& nums1, vector<int>& nums2) {
    int m=nums1.size(),n=nums2.size();
    unordered_map<int,int> mp;  // {val: next-greater}
    stack<int> stk;             // monotonically decreasing stack
    for (int i=0;i<n;++i) {     // O(n) traversenums2 to build map of its next-greater
      while (stk.size() && stk.top()<nums2[i])
        mp[stk.top()]=nums2[i];
      stk.push(nums2[i]);
    }
    vector<int> res(m,-1);
    for (int i=0;i<m;++i)       // O(m)
      if (mp.count(nums1[i]))   // has next-greater?
        res[i]=mp[nums1[i]];
    return res;
  }
};
class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& findNums, vector<int>& nums) {
    int m=findNums.size(),n=nums.size();
    unordered_map<int,int> mp;
    for (int i=0;i<n;++i) mp[nums[i]]=i;  // {val:idx} of nums
    vector<int> res(m,-1);
    for (int i=0;i<m;++i)                 // O(mn)
      for (int j=mp[findNums[i]];j<n;++j)
        if (nums[j]>findNums[i]) {
          res[i]=nums[j];
          break;
        }
    return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{4,1,2}, B1{1,3,4,2};
  for (auto n: s.nextGreaterElements(A1,B1)) cout << n << " ";
  cout << endl;
  vector<int> A2{2,4}, B2{1,2,3,4};
  for (auto n: s.nextGreaterElements(A2,B2)) cout << n << " ";
  cout << endl;
}
