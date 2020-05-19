#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int subtractProductAndSum(int n) {
    int prd=1,sum=0;
    while (n) {
      int v=n%10;
      prd*=v, sum+=v;
      n/=10;
    }
    return prd-sum;
  }
};
int main(){
  Solution s;
  cout << s.subtractProductAndSum(234) << endl;
  cout << s.subtractProductAndSum(4421) << endl;
}
