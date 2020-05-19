#include <bits/stdc++.h>
using namespace std;
class Solution1 {
public:
  string reverseParentheses(string s) {
    string res;
    unordered_map<int,int> mp;
    stack<int> stk;
    int n=s.size();
    for (int i=0;i<n;++i) {                           // O(n) to mark wormholes
      if (s[i]=='(') stk.push(i);
      else if (s[i]==')')
        mp[stk.top()]=i, mp[i]=stk.top(), stk.pop();  // wormholes, i to j, j to i
    }
    for (int i=0,d=1;i<n;i+=d) {
      if (s[i]=='('||s[i]==')')
        i=mp[i],d=-d;
      else
        res+=s[i];
    }
    return res;
  }
};
class Solution {
public:
  string reverseParentheses(string s) {
    string res;
    stack<int> stk;
    for (auto c: s) {
      if (c=='(')
        stk.push(res.size());             // defer
      else if (c==')') {
        int n=stk.top(); stk.pop();       // reverse once
        reverse(res.begin()+n, res.end());
      } else
        res+=c;
    }
    return res;
  }
};
int main(){
  Solution1 s;
  cout << s.reverseParentheses("(abcd)") << endl;
  cout << s.reverseParentheses("(u(love)i)") << endl;
  cout << s.reverseParentheses("a(bcdefghijkl(mno)p)q") << endl;
}
