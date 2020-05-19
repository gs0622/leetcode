#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isPossible(vector<int>& A) {
    long sum=0;
    for (auto a: A) sum+=a;
    auto i=max_element(A.begin(),A.end())-A.begin();
    while (sum>1 && A[i]>sum/2) {
      sum-=A[i];
      if (sum<=1) return sum;
      A[i]%=sum;
      sum+=A[i];
      i=max_element(A.begin(),A.end())-A.begin();
    }
    return sum==A.size();
  }
};
class Solution1 {
public:
  bool isPossible(vector<int>& A) {
    int sum=0;
    for (auto a: A) sum+=a;
    priority_queue<int> pq(A.begin(),A.end());
    while (sum>1 && pq.top()>sum/2) {
      int cur=pq.top();pq.pop();
      sum-=cur;
      if (sum<=1) return sum;
      pq.push(cur%sum);
      sum+=cur%sum;
    }
    return sum==pq.size();
  }
};
int main(){
  Solution s;
  vector<int> A1{9,5,3};
  cout << s.isPossible(A1) << endl;
}
