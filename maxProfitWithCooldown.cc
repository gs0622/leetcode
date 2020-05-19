#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxProfit(vector<int>& P) {
    int free=0,have=INT_MIN,cool=INT_MIN;
    for (auto p: P) {
      int free2=free,have2=have,cool2=cool;
      free=max(free2,cool2);
      have=max(have2,free2-p);
      cool=have2+p;
    }
    int res=max(free,cool);
    return res;
  }
};
int main(){
  Solution s;
  vector<int> P1{1,2,3,0,2};
/*

p   | x  1  2  3  0  2
free| 0  0  0  1  2  2
have| * -1 -1 -1  1  1
cool| *  *  1  2 -1  3
*/
  cout << s.maxProfit(P1) << endl;
}
