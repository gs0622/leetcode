#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int findTheDistanceValue(vector<int>& A1, vector<int>& A2, int d) {
    int n=A1.size(),res=0;
    for (int i=0;i<n;++i) {
      bool found=false;
      for (auto v: A2)
        if (abs(v-A1[i])<=d)
          found=true;
      if (!found) ++res;
    }
    return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{4,5,8},A2{10,9,1,8};
  cout << s.findTheDistanceValue(A1,A2,2) << endl; 
}
