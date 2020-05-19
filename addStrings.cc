/*
https://leetcode.com/problems/add-strings/description/

Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:
The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string addStrings(string num1, string num2) {
    int n=num1.size(), m=num2.size(), carry=0, sum;
    string res;
    while (n||m) {
      if (n && m) {
        sum  = (num1[n-1]-'0') + (num2[m-1]-'0') + carry;
        --n,--m;
      } else if (n==0 && m>0) {
        sum=num2[m-1]-'0'+carry, --m;
      } else if (n>0 && m==0) {
        sum=num1[n-1]-'0'+carry, --n;
      }
      carry=sum/10, sum%=10;
      res=to_string(sum) + res;
    }
    if (carry) res="1"+res;
    return res;
  }
};
int main(){
  Solution s;
  cout << s.addStrings("111", "222") << endl;
  cout << s.addStrings("999", "1") << endl;
}
