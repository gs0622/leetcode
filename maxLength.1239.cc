#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxLength(vector<string>& A) {
    int n=A.size(),res=0;
    vector<int> dp{0};
    for (auto s: A) {
      int msk=0,dup=0;
      for (auto c: s) {
        if (msk&1<<(c-'a')) {
          dup=1;
          break;
        }
        msk|=1<<(c-'a');
      }
      if (dup) continue;
  
      for (int i=dp.size()-1;i>=0;--i) {
        int msk2=dp[i];
        if (msk&msk2) continue;
        bitset<26> c(msk|msk2);
        dp.push_back(msk|msk2);
        res=max(res,(int)c.count());
      }
    }
    return res;
  }
};
class Solution1 {
public:
  int maxLength(vector<string>& A) {  // TLE
    int n=A.size();
    function<int(int,int,int)> helper=[&](int i, int mask, int len){
      if (i==n) return len; // terminal case
      int res=0,msk=0,taken=0,nottaken=0;
      for (auto c: A[i]) msk|=1<<(c-'a');
      if (mask & msk) return res;
      for (int j=i;j<n;++j) {
        taken=helper(i+1,mask|msk,len+A[i].size());
        nottaken=helper(i+1,mask,len);
        res=max(taken,nottaken);
      }
      return res;
    };
    return helper(0,0,0);
  }
};
int main(){
  Solution s;
  vector<string> A1{"un","iq","ue"};
  cout << s.maxLength(A1) << endl;
  vector<string> A2{"cha","r","act","ers"};
  cout << s.maxLength(A2) << endl;
  vector<string> A3{"abcdefghijklmnopqrstuvwxyz"};
  cout << s.maxLength(A3) << endl;
  vector<string> A4{"a","b","c","d","e"};
  cout << s.maxLength(A4) << endl;
}
