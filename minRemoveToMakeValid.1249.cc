#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string minRemoveToMakeValid(string s) {
    int n=s.size();
    stack<int> stk;
    for (int i=0;i<n;++i) {
      if (s[i]=='(') stk.push(i);
      else if (s[i]==')') {
        if (stk.size()) stk.pop();
        else s[i]='*';
      }
    }
    while (stk.size())
      s[stk.top()]='*', stk.pop();
  
    string res;
    for (auto c: s)
      if (c!='*') res+=c;
    return res;
  }
};
int main(){
  Solution s;
  cout << s.minRemoveToMakeValid("lee(t(c)o)de)") << endl;
  cout << s.minRemoveToMakeValid("))((") << endl;
}
