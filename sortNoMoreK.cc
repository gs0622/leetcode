/* https://www.geeksforgeeks.org/nearly-sorted-algorithm/
Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that sorts in O(n log k) time. For example, let us consider k is 2, an element at index 7 in the sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> sortK(vector<int>& A, int k) {
    int n=A.size(),i,j;
    priority_queue<int,vector<int>,greater<int>> pq(A.begin(),A.begin()+k+1); // O(klgk)
    for (i=k+1,j=0;i<n;++i) {     // O(n)
      A[j++]=pq.top(); pq.pop();  // O(lgk)
      pq.push(A[i]);
    }
    while (pq.size()) {           // O(n-k)
      A[j++]=pq.top(); pq.pop();
    }
    return A;
  }
};
int main(){
  Solution s;
  vector<int> A1{6, 5, 3, 2, 8, 10, 9}; // k=3
  for (auto n: s.sortK(A1,3)) cout << n << " ";
  cout << endl;
}
