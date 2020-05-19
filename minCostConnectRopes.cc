#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minCostConnectRopes(vector<int>& A) {
    priority_queue<int,vector<int>,greater<int>> pq(A.begin(),A.end()); // build minheap, O(nlogn)
    int res=0, a, b;
    while (pq.size()>1) {   // O(n)
      a=pq.top(),pq.pop();
      b=pq.top(),pq.pop();
      res+=a+b, pq.push(a+b);
    }
    return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{8, 4, 6, 12};
  cout << s.minCostConnectRopes(A1) << endl;
  vector<int> A2{20, 4, 8, 2};
  cout << s.minCostConnectRopes(A2) << endl;
  vector<int> A3{1,2,5,10,35,89};
  cout << s.minCostConnectRopes(A3) << endl;
  vector<int> A4{2,2,3,3};
  cout << s.minCostConnectRopes(A4) << endl;
}
