/*
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.
Example 1:
Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
Constraints:
arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
Each arr2[i] is distinct.
Each arr2[i] is in arr1.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int,int> mp;
    for (int i=0;i<arr1.size();++i) mp[arr1[i]]=1000+arr1[i];
    for (int i=0;i<arr2.size();++i) mp[arr2[i]]=i;
    sort(arr1.begin(),arr1.end(),[&](int a, int b){ return mp[a]<mp[b];});
    return arr1;
  }
};
int main(){
  Solution s;
  vector<int> A1{2,3,1,3,2,4,6,7,9,2,19},A2{2,1,4,3,9,6};
  for (auto n: s.relativeSortArray(A1,A2)) cout << n << " ";
  cout << endl;
  vector<int> A3{26,21,11,20,50,34,1,18},A4{21,11,26,20};
  for (auto n: s.relativeSortArray(A3,A4)) cout << n << " ";
  cout << endl;
}
