#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
    if (start==destination) return 0;
    if (start>destination) return distanceBetweenBusStops(distance,destination,start);
    int n=distance.size(),clockwise=destination-start, anti_clockwise=n%(clockwise);
    int sum1 = accumulate(distance.begin()+start, distance.begin()+destination,0);
    int sum2 = accumulate(distance.begin(), distance.end(),0)-sum1;
    return min(sum1,sum2);
  }
};
int main(){
  Solution s;
  vector<int> A1{1,2,3,4};
  cout << s.distanceBetweenBusStops(A1,0,1) << endl;
  cout << s.distanceBetweenBusStops(A1,0,2) << endl;
  cout << s.distanceBetweenBusStops(A1,0,3) << endl;
}
