/* https://leetcode.com/problems/car-pooling/description/
You are driving a vehicle that has capacity empty seats initially available for passengers.  The vehicle only drives east (ie. it cannot turn around and drive west.)

Given a list of trips, trip[i] = [num_passengers, start_location, end_location] contains information about the i-th trip: the number of passengers that must be picked up, and the locations to pick them up and drop them off.  The locations are given as the number of kilometers due east from your vehicle's initial location.

Return true if and only if it is possible to pick up and drop off all passengers for all the given trips. 

Constraints:

trips.length <= 1000
trips[i].length == 3
1 <= trips[i][0] <= 100
0 <= trips[i][1] < trips[i][2] <= 1000
1 <= capacity <= 100000
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool carPooling(vector<vector<int>>& trips, int capacity) { // O(n)
    int cnt[1001]={},load=0;
    for (auto t: trips) cnt[t[1]]+=t[0],cnt[t[2]]-=t[0];
    for (int i=0;i<1001;++i) {
      load+=cnt[i];
      if (load>capacity) return false;
    }
    return true;
  }
};
class Solution2 {
public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    int n=trips.size(), load=0;
    struct {
      bool operator()(vector<int>& a, vector<int>& b) {
        return a[1]<b[1]||(a[1]==b[1]&&a[2]<b[2]);
      };
    } cmp;
    sort(trips.begin(),trips.end(),cmp);    // O(nlogn)
    priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
    for (int i=0;i<n;++i) {
      load+=trips[i][0];
      if (pq.size()) {
        while (pq.size() && trips[i][1]>=pq.top()[0])
          load-=pq.top()[1], pq.pop();
      }
      if (load>capacity) return false;
      pq.push({trips[i][2],trips[i][0]});   // {drop,count}
    }
    return true;
  }
};
int main(){
  Solution s;
  vector<vector<int>> A1{{3,2,8},{4,4,6},{10,8,9}};
  cout << s.carPooling(A1,11) << endl;
}
