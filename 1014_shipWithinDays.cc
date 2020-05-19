/* https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

A conveyor belt has packages that must be shipped from one port to another within D days.
The i-th package on the conveyor belt has a weight of weights[i]. 
Each day, we load the ship with packages on the conveyor belt (in the order given by weights).
We may not load more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.

Note:
1 <= D <= weights.length <= 50000
1 <= weights[i] <= 500

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int shipWithinDays(vector<int>& weights, int D) {
    int total=accumulate(weights.begin(),weights.end(),0);
    if (D==1) return total;
    function<bool(int)> valid=[&](int cap){
      int d=1, sum=0;
      for (int w: weights) {
        sum+=w;
        if (sum>cap) sum=w, d+=1;
        if (d>D) return false;
      }
      return true;
    };
    int lo=*max_element(weights.begin(),weights.end()), hi=total;
    while (lo<hi) {
      int mi=lo+(hi-lo)/2;
      if (valid(mi)) hi=mi;
      else lo=mi+1;
    }
    return lo;
  }
};
int main(){
  Solution s;
  vector<int> A1{1,2,3,4,5,6,7,8,9,10};
  cout << s.shipWithinDays(A1,5) << endl;
  vector<int> A2{3,2,2,4,1,4};
  cout << s.shipWithinDays(A2,3) << endl;
  vector<int> A3{1,2,3,1,1};
  cout << s.shipWithinDays(A3,4) << endl;
}
