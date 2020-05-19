#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int countArrangement(int n) {
    vector<int> used(n+1);
    int res=0;
    function<void(int)> helper=[&](int pos){
      if (pos>n) {
        ++res;
        return;
      }
      for (int i=1;i<=n;++i) {
        if (used[i]==0&&(i%pos==0||pos%i==0)) {
          used[i]=1;
          helper(pos+1);
          used[i]=0;
        }
      }
    };
    helper(1);
    return res;
  }
};
int main(){}
