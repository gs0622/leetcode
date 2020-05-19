#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string removeDuplicates(string S) {
    stack<char> stk;
    for (auto c: S) {
      if (!stk.empty() && stk.top()==c)
        while (!stk.empty() && stk.top()==c)
          stk.pop();
      else
        stk.push(c);
    }
    string res;
    while (stk.size())
      res=stk.top()+res,stk.pop();
    return res;
  }
};
int main(){
  Solution s;
  cout << s.removeDuplicates("abbaca") << endl;
}
