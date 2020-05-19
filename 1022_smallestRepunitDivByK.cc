/* https://leetcode.com/problems/smallest-integer-divisible-by-k/description/
Given a positive integer K, you need find the smallest positive integer N such that N is divisible by K, and N only contains the digit 1.
Return the length of N.  If there is no such N, return -1.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int smallestRepunitDivByK(int K) {
    int res=1;  // length of N
    for (long i=0; res<=K; ++res) {
      i=(i*10+1)%K;
      if (i==0)
        return res;
    }
    return -1;
  }
};
int main(){
  Solution s;
  cout << s.smallestRepunitDivByK(3) << endl;
  cout << s.smallestRepunitDivByK(12) << endl;
  cout << s.smallestRepunitDivByK(20) << endl;
}
