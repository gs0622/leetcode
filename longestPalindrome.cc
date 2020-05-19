/* https://leetcode.com/problems/longest-palindrome/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public: // naive O(cN) c='A' to 'z': 65 to 122
  int longestPalindrome(string s) {
    int n=s.size(), odds=0;
    for (char c='A'; c<='z'; ++c) // 65 to 122
      odds+=count(s.begin(),s.end(),c)&1;
    return n-odds+(odds>0);
  }
};
class Solution {
public: // naive O(n^2), wrong to double counting, think why? hint: the loop is wrong
  int longestPalindrome(string s) {
    int n=s.size(), odds=0;
    for (auto c: s)
      odds+=count(s.begin(),s.end(),c)&1;
    return n-odds+(odds>0);
  }
};
int main(){
  Solution2 s;
  string S1{"abccccdd"};
  cout << s.longestPalindrome(S1) << endl;
  string S2{"ccc"};
  cout << s.longestPalindrome(S2) << endl;
}
