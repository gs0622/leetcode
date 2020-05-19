#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool backspaceCompare(string S, string T) {
    function<string(string)> helper=[](string s){
      string res;
      for (auto c: s) {
        if (c!='#') res.push_back(c);
        else
          if (!res.empty())
            res.pop_back();
      }
      return res;
    };
    return helper(S)==helper(T);
  }
};
class Solution1 {
public:
  bool backspaceCompare(string S, string T) {
    stack<char> stk1,stk2;
    for (auto c: S) {
      if (c=='#') {
        if (!stk1.empty())
          stk1.pop();
      } else
        stk1.push(c);
    }
    for (auto c: T) {
      if (c=='#') {
        if (!stk2.empty())
          stk2.pop();
      } else
        stk2.push(c);
    }
    return stk1==stk2;
  }
};
int main(){
  Solution s;
  cout << s.backspaceCompare("y#fo##f","y#f#o##f") << endl;
}
