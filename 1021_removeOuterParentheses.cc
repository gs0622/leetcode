#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string removeOuterParentheses(string s) {
    string res;
    int cnt=0;
    for (auto c: s) {
      if (c=='(' && cnt++ > 0) res+=c;
      if (c==')' && cnt-- > 1) res+=c;
    }
    return res;
  }
};
int main(){
  Solution s;
  cout << s.removeOuterParentheses("(()())(())") << endl;
  cout << s.removeOuterParentheses("(()())(())(()(()))") << endl;
  cout << s.removeOuterParentheses("()()") << endl;
}
