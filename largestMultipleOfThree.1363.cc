/* https://leetcode.com/problems/middle-of-the-linked-list/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public: // sum -> filter -> construct
  string largestMultipleOfThree(vector<int>& A) {
    int D[10]={},sum=0;
    vector<int> m1{1,4,7,2,5,8}, m2{2,5,8,1,4,7};

    // sum
    for (auto d: A)
      ++D[d], sum+=d;

    // filter
    while (sum%3!=0) {
      for (auto i: sum%3==1? m1: m2) {
        if (D[i]) {
          --D[i],sum-=i;
          break;  // break for, goto while
        }
      }
    }

    // construct (sum%3==0)
    string res;
    for (int i=9;i>=0;--i)
      res+=string(D[i],'0'+i);  // (size_t,char)
    return res.size()&&res[0]=='0'? "0": res;
  }
};
int main(){
  Solution s;
  vector<int> A1{8,1,9};
  cout << s.largestMultipleOfThree(A1) << endl;
}
