#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public: // O(n)
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> res(n);
    for (auto b: bookings) {  // mark
      res[b[0]-1]+=b[2];
      if (b[1]<n) res[b[1]]-=b[2];
    }
    for (auto i=1;i<n;++i)    // sum
      res[i]+=res[i-1];
    return res;
  }
};
class Solution {
public: // naive O(n^2) TLE
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> res(n,0);
    for (int i=0; i<bookings.size(); ++i) {
      for (int j=bookings[i][0]; j<=bookings[i][1]; ++j)
        res[j-1]+=bookings[i][2];
    }
    return res;
  }
};
int main(){
  Solution2 s;
  vector<vector<int>> A1{{1,2,10},{2,3,20},{2,5,25}};
  for (auto n: s.corpFlightBookings(A1,5)) cout << n << " ";
  cout << endl;
}
