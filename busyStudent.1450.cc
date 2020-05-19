#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int busyStudent(vector<int>& S, vector<int>& E, int Q) {
    int n=S.size(),res=0;
    for (int i=0;i<n;++i)
      if (S[i]<=Q && E[i]>=Q)
        ++res;
    return res;
  }
};
int main(){}
