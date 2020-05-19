#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> pathInZigZagTree(int label) {
    int level=0;
    while (1<<level <= label) ++level;
    vector<int> res(level);
    while (label>0) {
      res[level-1]=label;
      //int a=1<<(level-1);
      //int b=((1<<level)-1-label);
      //label=a+b;
      label=((1<<level)-1-label)+(1<<(level-1));
      --level,label/=2;
    }
    return res;
  };
};
int main(){
  Solution s;
  for (auto n: s.pathInZigZagTree(14)) cout << n << " ";
  cout << endl;
  for (auto n: s.pathInZigZagTree(26)) cout << n << " ";
  cout << endl;
  for (auto n: s.pathInZigZagTree(16)) cout << n << " ";
  cout << endl;
}
