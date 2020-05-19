#include <bits/stdc++.h>
using namespace std;
class Solution3 {
public:
  int kthGrammar(int N, int K) {
    int res=0;
    while (K>1) {
      K=(K%2==1)? K+1: K/2;
      res^=1;
    }
    return res;
  }
};
class Solution2 {
public:
/* o: odd, e: even
       0
     0     1
    0 1   1 0
   01 10 10 01
   oe oe oe oe
*/
  int kthGrammar(int N, int K) {
    if (N==1) return 0;
    if (K%2==0) // even, be a right child
      return (kthGrammar(N-1,K/2)==0)? 1: 0;      // 2nd of 01
    else        // odd
      return (kthGrammar(N-1,(K+1)/2)==0)? 0: 1;  // 1st of 01
  }
};
class Solution {
public:
  int kthGrammar(int N, int K) {
    string s="0";
    for (int i=1;i<N;++i) {
      string s2;
      for (auto ch: s) {
        if (ch=='0') s2+="01";
        else s2+="10";
      }
      s.swap(s2);
    }
    return s[K-1]-'0';
  }
};
int main(){
  Solution3 s;
  cout << s.kthGrammar(1,1) << endl;
  cout << s.kthGrammar(2,1) << endl;
  cout << s.kthGrammar(2,2) << endl;
  cout << s.kthGrammar(4,5) << endl;
  cout << s.kthGrammar(30,434991989) << endl;
}
