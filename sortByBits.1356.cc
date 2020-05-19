#include <bits/stdc++.h>
using namespace std;
class Solution {
  vector<int> sortByBits(vector<int>& A) {
    sort(A.begin(),A.end(),[](int a, int b){
      int ca=__builtin_popcount(a),cb=__builtin_popcount(b);
      return ca<cb||(ca==cb && a<b);
    });
    return A;
  }
};
int main(){}
