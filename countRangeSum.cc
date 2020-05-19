/* https://leetcode.com/problems/count-of-range-sum/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public: // naive O(n^2)
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    int n=nums.size(),res=0;
    for (int i=0;i<n;++i) {
      long sum=0;
      for (int j=i;j<n;++j) {
        sum+=nums[j];
        if (sum>=lower&&sum<=upper)++res;
      }
    }
    return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{-2,5,-1};
  cout << s.countRangeSum(A1,-2,2) << endl;
}
