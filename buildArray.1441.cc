#include <bits/stdc++.h>
using namespace std;
class Solution {
  vector<string> buildArray(vector<int>& A, int n) {
    int nn=min(n,A.back());
    unordered_set<int> st(A.begin(),A.end());
    vector<string> res;
    for (int i=1;i<=nn;++i) {
      if (st.count(i)) res.push_back("Push");
      else res.push_back("Push"), res.push_back("Pop");
    }
    return res;
  }
};
int main(){}
