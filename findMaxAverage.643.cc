/*
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  double findMaxAverage(vector<int>& nums, int k) {
    int n=nums.size();
    vector<int> sums(nums);
    for (int i=1;i<n;++i) sums[i]+=sums[i-1];
    double res=(double)sums[k-1]/k;  // [0...k-1]
    for (int i=k;i<n;++i) {
      double avg=(double)(sums[i]-sums[i-k])/k;
      res=max(res,avg);
    }
    return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{1,12,-5,-6,50,3};
  cout << s.findMaxAverage(A1,4) << endl;
  vector<int> A2{4,0,4,3,3};
  cout << s.findMaxAverage(A2,5) << endl;
}
