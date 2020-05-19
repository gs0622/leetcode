#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<bool> prefixesDivBy5(vector<int>& A) {
    int n=A.size(), num=0;
    vector<bool> res;
    for (int i=0;i<n;++i) {
      num<<=1, num+=A[i], num%=5; // hint: modulo
      res.push_back(num==0);
    }
    return res;
  }
};
int main(){
}
