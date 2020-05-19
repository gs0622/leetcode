#include <bits/stdc++.h>
using namespace std;
class Solution2 {
  string nextPermutation(string& s) {
    int n=s.size(), i;
    for (i=n-2;i>=0;--i)
      if (s[i]<s[i+1]) break;
    reverse(s.begin()+i+1,s.end()); // think in case i==-1
    if (i==-1) return s;
    auto it=upper_bound(s.begin()+i+1,s.end(),s[i]);
    swap(*it,s[i]);
    return s;
  }
public:
  int nextGreaterElement(int n) {
    string s=to_string(n);
    s=nextPermutation(s);
    long n2=stol(s);
    return (n2>n && n2<=INT_MAX)? n2: -1;
  }
};
class Solution {
public:
  int nextGreaterElement(int n) {
    string s=to_string(n);
    next_permutation(s.begin(),s.end());
    long n2=stol(s);
    //cout << n2 << endl;
    return (n2>n && n2<=INT_MAX)? n2: -1;
  }
};
int main(){
  Solution2 s;
  cout << s.nextGreaterElement(12) << endl;
  cout << s.nextGreaterElement(21) << endl;
  cout << s.nextGreaterElement(1999999999) << endl;
}
