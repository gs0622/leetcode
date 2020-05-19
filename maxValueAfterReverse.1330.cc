#include <bits/stdc++.h>
using namespace std;
class Solution {  // O(n) time, one pass
public:
  int maxValueAfterReverse(vector<int>& A) {
    int n=A.size(),sum=0,res=0,min2=2e5,max2=-2e5;
    for (int i=0;i<n-1;++i) {
      // think: x, y, ..., a, [b, ..., c], d, ...,
      int a=A[i],b=A[i+1];
      sum+=abs(a-b);
      res=max(res,abs(A[0]-b)-abs(a-b));
      res=max(res,abs(A[n-1]-a)-abs(a-b));
      min2=min(min2,max(a,b));
      max2=max(max2,min(a,b));
    }
    return sum+max(res,(max2-min2)*2);
  }
};
class Solution2 {  // O(n^3), brute-force, TLE
public:
  int maxValueAfterReverse(vector<int>& A) {
    int n=A.size(),res=0;
    for (int i=0;i<n;++i) for (int j=i+1;j<n;++j) { // O(n^2 emunerate start/end)
      reverse(A.begin()+i,A.begin()+j+1);           // O(n) reverse [start:end]
      int sum=0;
      for (int k=0;k<n-1;++k)                       // O(n) calculate the sum
        sum+=abs(A[k]-A[k+1]);
      res=max(res,sum);
      reverse(A.begin()+i,A.begin()+j+1);
    }
    return res;
  }
};
int main(){
  Solution s;
  //vector<int> A1{2,3,1,5,4};
  vector<int> A1{2,4,9,24,2,1,10};
  cout << s.maxValueAfterReverse(A1) << endl;;
}
