/*
Given an array consisting of n integers, find the contiguous subarray whose length is greater than or equal to k that has the maximum average value. And you need to output the maximum average value.

Example 1:

Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation:
when length is 5, maximum average value is 10.8,
when length is 6, maximum average value is 9.16667.
Thus return 12.75.
 

Note:

1 <= k <= n <= 10,000.
Elements of the given array will be in range [-10,000, 10,000].
The answer with the calculation error less than 10-5 will be accepted.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public: // O(n^2) approach
  double findMaxAverage(vector<int>& nums, int k) {
    int n=nums.size();
    vector<int> sum(nums);
    for (int i=0;i<n;++i) sum[i]+=sum[i-1];
    double res=(double)sum[k-1]/k;    // [0:k-1]
    for (int i=k;i<n;++i) { // (k+1)th
      //double sum2=sum[i]-sum[i-k], avg2=sum2/k;
      //res=max(res,avg2);
      //cout << avg2 << endl;
      for (int j=i;j<n;++j) {
        double sum3=sum[j]-sum[i-k];
        double avg3=sum3/(k+j-i);
        cout << avg3 << endl;
        res=max(res,avg3);
      }
    }
    return res;
  }
};
class Solution {
public:
  double findMaxAverage(vector<int>& nums, int k) {
    int n=nums.size();
    double res=DBL_MIN;
    for (int i=0;i<n-k;++i) {       // start
      for (int j=k;j<=n-i;++j) {  // length
        int sum=accumulate(nums.begin()+i,nums.begin()+i+j,0);  // suck! this one makes it becomes O(n^3)
        double avg=(double)(sum)/j;
        cout << avg << endl;
        res=max(avg,res);
      }
    }
    return res;
  }
};
int main(){
  Solution s;
  Solution2 s2;
  vector<int> A1{1,12,-5,-6,50,3};
  cout << s.findMaxAverage(A1,4) << endl;
  cout << endl;
  cout << s2.findMaxAverage(A1,4) << endl;
}
