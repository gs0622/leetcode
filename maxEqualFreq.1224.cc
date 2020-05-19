/* https://leetcode.com/problems/maximum-equal-frequency/description/
Given an array nums of positive integers, return the longest possible length of an array prefix of nums
such that it is possible to remove exactly one element from this prefix so that every number that has appeared in it will have the same number of occurrences.

If after removing one element there are no remaining elements, it's still considered that every appeared number has the same number of ocurrences (0).
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxEqualFreq(vector<int> nums) {
    unordered_map<int,int> cnt;   //  {key:freq}
    unordered_map<int,int> freq;  //  {freq: cnt}
    int n=nums.size(), res=0;
    for (int i=0;i<n;++i) {
      ++cnt[nums[i]];
      int f=cnt[nums[i]];
      ++freq[f];
      int c=freq[f]*f;  // expected len == freq times the count of this freq == maxEqualFreq
      if (c==i+1 && i<n-1)              // 1,1,2,2,3
        res=max(res,i+2);               //       -   i==3
      else if (c==i)                    // 1,1,1,2,2,3
        res=max(res,i+1);               //         - i==4
    }
    return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{2,2,1,1,5,3,3,5};
  cout << s.maxEqualFreq(A1) << endl;
  vector<int> A2{1,1,1,2,2,2,3,3,3,4,4,4,5};
  cout << s.maxEqualFreq(A2) << endl;
}
