/*
Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements. 
Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<int>> minimumAbsDifference(vector<int>& A) {
    int n=A.size();
    sort(A.begin(),A.end());
    vector<int> B(n,INT_MAX);
    for (int i=1;i<n;++i) B[i]=A[i]-A[i-1];
    int min=*min_element(B.begin(),B.end());
    vector<vector<int>> res;
    for (int i=1;i<n;++i) {
      if (B[i]==min)
        res.push_back({A[i-1],A[i]});
    }
    return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{4,2,1,3};
  //for (auto p: s.minimumAbsDifference(A1)) cout << p[0] << "," << p[1] << endl;
  vector<int> A2{1,3,6,10,15};
  //for (auto p: s.minimumAbsDifference(A2)) cout << p[0] << "," << p[1] << endl;
  vector<int> A3{3,8,-10,23,19,-4,-14,27};
  for (auto p: s.minimumAbsDifference(A3)) cout << p[0] << "," << p[1] << endl;
}
