#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> minSubsequence(vector<int>& A) {
    int sum1=0,sum2=0;
    for (auto a: A) sum1+=a;
    priority_queue<int> pq(A.begin(),A.end());
    vector<int> res;
    while (sum1>=sum2) {
      int val=pq.top();pq.pop();
      res.push_back(val);
      sum2+=val,sum1-=val;
    }
    return res;
  }
};
int main(){}
