#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxSumDivThree(vector<int>& A) {  // TLE
    int n=A.size(), res=0;
    function<void(int,int)> helper=[&](int i, int sum){
      if (sum%3==0 && sum>res)
        res=sum;
      for (int j=i; j<n; ++j) {
        helper(j+1,sum);  // not taken;
        sum+=A[j];
        helper(j+1,sum);  // taken;
      }
    };
    helper(0,0);
    return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{3,6,5,1,8};
  cout << s.maxSumDivThree(A1) << endl;
  vector<int> A2{4};
  cout << s.maxSumDivThree(A2) << endl;
  vector<int> A3{1,2,3,4,4};
  cout << s.maxSumDivThree(A3) << endl;
}
