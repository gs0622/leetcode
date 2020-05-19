#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> res;
    function<void(int)> helper=[&](int v){
      if (v>=low && v<=high) {
        res.push_back(v);
        //return;
      }
      int vv=v%10;
      if (vv+1<10)
        helper(v*10+vv+1);
    };
    for (int i=1;i<=9;++i)
      helper(i);
    sort(res.begin(),res.end());
    return res;
  }
};
int main(){
  Solution s;
  for (auto n: s.sequentialDigits(1000,13000)) cout << n << " ";
  cout << endl;
}
