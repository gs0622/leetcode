/* https://leetcode.com/problems/circular-array-loop/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool circularArrayLoop(vector<int>& A) {
    int n=A.size();
    function<int(int)> next=[&](int i) {
      return (n+A[i]+i)%n;
    };
    for (int i=0;i<n;++i)
      A[i]%=n;
    for (int i=0;i<n;++i) {
      int slow=i,fast=i;
      while (A[slow]*A[next(fast)]>0 && A[slow]*A[next(next(fast))]>0) {
        slow=next(slow),fast=next(next(fast));
        if (slow==fast) {
          if (slow==next(slow))
            return false;
          return true;
        }
      }
      int j=i,val=A[i];
      while (A[j]*val>0) {
        int nx=next(j);
        A[j]=0,j=nx;
      }
    }
    return false;
  }
};
class Solution2 {
public:
  bool circularArrayLoop(vector<int>& nums) {
    if (nums.empty()) return false;
    unordered_set<int> st;
    int n=nums.size(), i=0;
    int forward=nums[0]>0;
    while (1) {
      assert(i<n && i>=0);
      if (st.count(i))
        return st.size()!=n;
      if (nums[i]>0 != forward)
        return false;
      st.insert(i);
      i+=nums[i];
      while (i<0) i+=n;
      i%=n;
    }
  }
};
class Solution3 {
public:
  bool circularArrayLoop(vector<int>& nums) {
    unordered_set<int> st;
    int n=nums.size();
    for (int i=0; i<n; ++i) {
      int j=(i+nums[i]+n)%n;
      if (st.count(j)) return true;
      st.insert(i);
    }
    return false;
  }
};
int main(){
  Solution2 s;
  vector<int> A1{-2,-17,-1,-2,-2};
  cout << s.circularArrayLoop(A1) << endl;
}
