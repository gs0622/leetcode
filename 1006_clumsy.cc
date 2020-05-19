#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
  int clumsy(int N) {
    if (N==0) return 0;
    if (N==1) return 1;
    if (N==2) return 2;
    if (N==3) return 6;
    function<int(int)> helper=[&](int n) {  
      if (n==0) return 0;
      if (n==1||n==2||n==3) return 1;
      if (n==4) return -2;
      if (n==5) return 0;
      return helper((n-2)%4+2);
    };
    return N*(N-1)/(N-2)+helper(N-3); // * / + ...
  }
};
class Solution {
public:
  int clumsy(int N) {
    if (N==0) return 0;
    if (N==1) return 1;
    if (N==2) return 2;
    if (N==3) return 6;
    function<int(int)> helper=[&](int n) {  
      if (n==0) return 0;
      if (n==1||n==2||n==3) return 1;
      return n-(n-1)*(n-2)/(n-3)+helper(n-4); // - * / + 
    };
    return N*(N-1)/(N-2)+helper(N-3); // * / + ...
  }
};
int main(){
  Solution2 s;
  cout << s.clumsy(4) << endl;
  cout << s.clumsy(10) << endl;
}

