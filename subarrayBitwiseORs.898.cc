#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int subarrayBitwiseORs(vector<int>& A) {
    unordered_set<int> pre,cur,res;
    for (auto n: A) {
      cur={n};
      for (auto m: pre)
        cur.insert(n|m);
      pre=cur;          // save old ORs sum
      for (auto m: cur)
        res.insert(m);
    }
    return res.size();
  }
};
class Solution2 {
public:
  int subarrayBitwiseORs(vector<int>& A) {  // TLE
    int n=A.size();
    unordered_set<int> st;
    for (int i=0;i<n;++i) {
      int sum=0;
      for (int j=i;j<n;++j)
        sum|=A[j], st.insert(sum);
    }
    return st.size();
  }
};
int main(){
  Solution s;
  vector<int> A1{1,1,2};
  cout << s.subarrayBitwiseORs(A1) << endl;
}
