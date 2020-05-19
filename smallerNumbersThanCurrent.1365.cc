#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int>& A) {
    int n=A.size();
    vector<int> res(n),cnt(101);
    for (auto n: A) ++cnt[n];
    for (int i=1;i<101;++i)
      cnt[i]+=cnt[i-1];
    for (int i=0;i<n;++i)
      res[i]=A[i]?cnt[A[i]-1]:0;
    return res;
  }
};
class Solution2 {
public: // O(n^2)
  vector<int> smallerNumbersThanCurrent(vector<int>& A) {
    int n=A.size();
    vector<int> res(n);
    for (int i=0;i<n;++i) {
      for (int j=0;j<n;++j)
        if (i!=j && A[j]<A[i]) ++res[i];
    }
    return res;
  }
};
int main(){}
