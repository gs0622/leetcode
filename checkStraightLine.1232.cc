#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool checkStraightLine(vector<vector<int>>& P) {
    int n=P.size();
    if (n<=2) return true;
    int dx=P[1][0]-P[0][0], dy=P[1][1]-P[0][1];
    for (int i=2;i<n;++i) {
      if ((P[i][0]-P[0][0])*dy != (P[i][1]-P[0][1])*dx)
        return false;
    }
    return true;
  }
};
int main(){
  Solution s;
  vector<vector<int>> A1{{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
  cout << s.checkStraightLine(A1) << endl;
}
