/* 
Write a function that takes a number as input and outputs the biggest number with the same set of digits.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int largestPermutation(int n) {
    priority_queue<int> pq;   // this gives lexi order
    while (n)
      pq.push(n%10), n/=10;
    int res=0;
    while (pq.size())
      res=res*10+pq.top(), pq.pop();
    return res;
  }
};
int main(){
  Solution s;
  cout << s.largestPermutation(423865) << endl; //865432
  cout << s.largestPermutation(809) << endl;
}
