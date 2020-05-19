/* https://leetcode.com/problems/grumpy-bookstore-owner/description/
*/
#include <bits/stdc++.h>
using namespace std;
static const auto ioSpeedUp = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  return nullptr;
}();
class Solution {
public: // sliding window [0...i-X...i...]
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    int n=customers.size(),res=0, tmp=0, opt=0;
    for (int i=0;i<n;++i) {
      res+=grumpy[i]==0? customers[i]:0;
      tmp+=grumpy[i]==1? customers[i]:0;
      if (i>=X) tmp-= grumpy[i-X]==1? customers[i-X]: 0;
      opt=max(opt,tmp);
    }
    return res+opt;
  }
};
int main(){
  Solution s;
  vector<int> C1{9,10,4,5}, G1{1,0,1,1};
  cout << s.maxSatisfied(C1,G1,1) << endl;
}
