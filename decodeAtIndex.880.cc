#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string decodeAtIndex(string S, int K) {
    int i, n;
    for (i=0,n=0;n<K;++i) {
      if (isdigit(S[i])) n*=S[i]-'0';
      else ++n;
    } // n>=K
    while (i--) {
      if (isdigit(S[i])) n/=S[i]-'0', K%=n; // div then mod
      else if (K%n==0)
        return string(1,S[i]);
      else n--;
    }
    return "bug";
  }
};
class Solution2 {  // MLE
  string helper(string& S, int& K) {
    string res;
    int n=S.size();
    for (int i=0;i<n;++i) {
      char ch = S[i];
      if (!isdigit(ch)) res+=ch;
      else {
        string s=res;
        for (int j=1;j<S[i]-'0'; ++j)
          res+=s;
      }
      if (res.size()>=K)
        break;
    }
    return res;
  }
public:
  string decodeAtIndex(string S, int K) {
    auto s=helper(S,K);
    return s.substr(K-1,1);
  }
};
int main(){
  Solution s;
  cout << s.decodeAtIndex("leet2code3",10) << endl;
  cout << s.decodeAtIndex("ha22",5) << endl;
  cout << s.decodeAtIndex("a2345678999999999999999",1) << endl;
  cout << s.decodeAtIndex("a2b3c4d5e6f7g8h9",10) << endl;
}
