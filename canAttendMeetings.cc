#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool canAttendMeetings(vector<vector<int>>& A) {
    int n=A.size();
    for (int i=1;i<n;++i) {
      if (A[i][0]<A[i-1][1])
        return false;
    }
    return true;
  }
};
int main() {
  Solution s;
  vector<vector<int>> A1{{0, 30},{5, 10},{15, 20}};
  cout << s.canAttendMeetings(A1) << endl;
}
