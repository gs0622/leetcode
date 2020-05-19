#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int carFleet(int target, vector<int>& pos, vector<int>& spd) {
    int n = pos.size();
    map<int,double> mp;
    for (int i=0;i<n;++i)
      mp[-pos[i]]=(double)(target-pos[i])/spd[i]; // {-pos: time}, -pos, sort near to far
    int res=0;
/*
cur records the current biggest time (the slowest)

If another car needs less or equal time than cur,
it can catch up this car fleet.

If another car needs more time,
it will be the new slowest car,
and becomes the new lead of a car fleet.
*/
    double cur=0;
    for (auto it: mp)   // near to far
      if (it.second > cur)
        cur=it.second, ++res;
    return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{10,8,0,5,3}, B1{2,4,1,1,3};
  cout << s.carFleet(12,A1,B1) << endl;
}
