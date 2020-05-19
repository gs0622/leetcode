/* https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/
Given an array nums of integers, return how many of them contain an even number of digits.
Constraints:
1 <= nums.length <= 500
1 <= nums[i] <= 10^5
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int findNumbers(vector<int>& A) {
    int res=0;
    for (auto n: A) {
      if (n>=10 && n<=99) ++res;
      else if (n>=1000 && n<=9999) ++res;
      else if (n==1e5) ++res;
    }
    return res;
  }
};
class Solution2 {
  int digits(int n) {
    int res=0;
    while (n)
      n/=10,++res;
    return res;
  }
public:
  int findNumbers(vector<int>& A) {
    int res=0;
    for (auto n: A)
      res+=(digits(n)%2==0);
    return res;
  }
};
int main(){}
