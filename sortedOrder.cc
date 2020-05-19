#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
  vector<int> sortedOrder(vector<int>& A) {
    int n=A.size();
    unordered_map<int,int> mp;
    vector<int> B(A);                   // copy
    sort(B.begin(),B.end());            // sort
    for (int i=0; i<n; ++i) mp[B[i]]=i; // sorted index
    vector<int> res(n);
    for (int i=0; i<n; ++i)
      res[i]=mp[A[i]];                  // map unsorted A[i] to sorted B[i]
    return res;
  }
}; 
class Solution {
public:
  vector<int> sortedOrder(vector<int>& A) {
    int n=A.size();
    unordered_map<int,int> mp;
    vector<int> B(A);                   // copy
    sort(B.begin(),B.end());            // sort
    for (int i=0; i<n; ++i) mp[B[i]]=i; // sorted index
    vector<int> res(n);
    for (int i=0; i<n; ++i)
      res[mp[B[i]]]=mp[A[i]];           // map unsorted A[i] to sorted B[i]
    return res;
  } 
};
int main(){
  Solution2 s;
  vector<int> A1{10,8,3,6,25};
  //            {3,6,8,10,25}
  //            {3,2,0,1,4}
  for (auto n: s.sortedOrder(A1)) cout << n << " ";
  cout << endl;
}
