/*
Given a binary string S (a string consisting only of '0' and '1's) and a positive integer N, return true if and only if for every integer X from 1 to N, the binary representation of X is a substring of S.

1 <= S.length <= 1000
1 <= N <= 10^9
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool queryString(string S, int N) {
    for (int i=1; i<=N; ++i) {
      string s= bitset<32>(i).to_string();
      if (S.find(s.substr(s.find("1")))==string::npos)
        return false; 
    }
    return true;
  }
};
int main(){
  Solution s;
  cout << s.queryString("0110",3) << endl;
  cout << s.queryString("0110",4) << endl;
}
