#include <bits/stdc++.h>
using namespace std;
class Solution {
public: // O(n) uses mono decreasing stack and map
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n=nums2.size();
    unordered_map<int,int> mp;  // {key,nextgreater}
    stack<int> stk;
    for (int i=0;i<n;++i) {
      while (stk.size() && nums2[i] > stk.top())
        mp[stk.top()]=nums2[i], stk.pop();
      stk.push(nums2[i]);       // defer key
    }
    vector<int> res(nums1);
    for (auto& n: res)
      n=mp.count(n)? mp[n]: -1;
    return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{4,1,2}, A2{1,3,4,2};
  for (auto n: s.nextGreaterElement(A1,A2)) cout << n << " ";
  cout << endl;
}
