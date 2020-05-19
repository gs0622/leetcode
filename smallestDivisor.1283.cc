/* https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor and divide all the array by it and sum the result of the division. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

It is guaranteed that there will be an answer.

Constraints:
1 <= nums.length <= 5 * 10^4
1 <= nums[i] <= 10^6
nums.length <= threshold <= 10^6

*/
#include <bits/stdc++.h>
using namespace std;
namespace {
int div_roundup(int n, int d) {
  if (n%d) return (n+d)/d;
  else return n/d;
}
};
class Solution {
public:
  int smallestDivisor(vector<int>& A, int T) {
    int lo=1,hi=1e6;
    while (lo<hi) {
      int mi=lo+(hi-lo)/2, sum=0;
      for (auto n: A)
        sum+=(n+mi-1)/mi;
      if (sum>T) lo=mi+1;   // divisor is too small
      else hi=mi;           // sum<=T
    }
    return lo;   
  }
};
class Solution3 {
public:
  int smallestDivisor(vector<int>& A, int T) {
    long sum=0;
    for (auto n: A) sum+=n;
    if (sum<=T) return 1;
    long lo=2, hi=sum;
    while (lo<hi) {
      long mi=lo+(hi-lo)/2, sum2=0;
      for (auto n: A)
        sum2+=div_roundup(n,mi);
        //sum2+=(n+mi-1)/mi;
      //if (sum2==T) return mi;   // this is wrong, becasue we need the smallest div
      if (sum2>T) lo=mi+1; // div too small
      else hi=mi;
    }
    return (int)lo;
  }
};
class Solution2 {
public:
  int smallestDivisor(vector<int>& A, int T) {  // brute-force: TLE
    int d=0, sum=INT_MAX;
    while (sum > T) {
      sum = 0, ++d;
      for (auto n: A)
        sum += div_roundup(n,d);
    }
    return d;
  }
};
int main(){
  Solution s;
  vector<int> A1{1,2,5,9};
  //cout << s.smallestDivisor(A1,6) << endl;
  vector<int> A2{2,3,5,7,11};
  //cout << s.smallestDivisor(A2,11) << endl;
  vector<int> A3{19};
  //cout << s.smallestDivisor(A3,5) << endl;
  vector<int> A4{962551,933661,905225,923035,990560};
  cout << s.smallestDivisor(A4,10) << endl;
}
