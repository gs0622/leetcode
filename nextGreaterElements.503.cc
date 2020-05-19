/* https://leetcode.com/problems/next-greater-element-ii/description/
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element.
The Next Greater Number of a number x is the first greater number to its traversing-order next in the array,
which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution3 {
public: // O(n^2)
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n=nums.size();
    vector<int> res(n,-1);
    for (int i=0;i<n;++i) {
        for (int j=i+1;j<n*2+i;++j) {
            if (nums[j%n]>nums[i]) {
                res[i]=nums[j%n];
                break;  // next-greater
            }
        }
    }
    return res;
  }
};
class Solution2 {
public: // O(n) using stack
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n=nums.size();
    vector<int> res(n,-1);
    stack<int> stk;
    for (int i=0;i<2*n;++i) {
        while (stk.size() && nums[stk.top()]<nums[i%n])
            res[stk.top()]=nums[i%n],stk.pop();
        if (i<n) stk.push(i);
    }
    return res;
  }
};
class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n=nums.size();
    vector<int> res(n,INT_MIN);
    for (int i=0;i<2*n;++i) {   // O(n^2)
      for (int j=i+1;j<2*n;++j)
        if (nums[j%n]>nums[i%n])
          if (res[i%n]==INT_MIN) res[i%n]=nums[j%n];
    }
    for (auto& n: res) if (n==INT_MIN) n=-1;
    return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{1,2,1};
  for (auto n: s.nextGreaterElements(A1)) cout << n << " ";
  cout << endl;
  vector<int> A2{1,8,-1,-100,-1,222,1111111,-111111};
  for (auto n: s.nextGreaterElements(A2)) cout << n << " ";
  cout << endl;
}
