#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string reverseWords(string s) {
    istringstream is(s);
    string res,w;
    while (is>>w) {
      reverse(w.begin(),w.end());
      res+=w;
      if (!is.eof())
        res+=" ";
    }
    return res;
  }
};
int main(){
  Solution s;
  cout << s.reverseWords("Let's take LeetCode contest") << endl;
}
