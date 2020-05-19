#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> largestSubarrayLenK(vector<int>& A, int K) {
  }
};
class Solution3 {
public:
  vector<int> largestSubarrayLenK(vector<int>& A, int K) {
    struct mycmp {
      bool operator()(deque<int>& a, deque<int>& b) {
        int n=a.size();
        for (int i=0;i<n;++i) {
          if (a[i]==b[i]) continue;
          if (a[i]>b[i]) return false;
          return true;  // a[i]<b[i]
        }
        return true;
      }
    };
    priority_queue<deque<int>,vector<deque<int>>, mycmp> pq;
    int n=A.size();
    deque<int> dq(A.begin(),A.begin()+K);
    pq.push(dq);
    for (int i=K;i<n;++i) {
      dq.pop_front(), dq.push_back(A[i]);
      pq.push(dq);
    }
    auto t=pq.top();
    return vector<int>(t.begin(),t.end());
  }
};
class Solution2 {
public:
  vector<int> largestSubarrayLenK(vector<int>& A, int K) {
    struct mycmp {
      bool operator()(vector<int>& a, vector<int>& b) {
        int n=a.size();
        for (int i=0;i<n;++i) {
          if (a[i]==b[i]) continue;
          if (a[i]>b[i])
            return false;
          else
            return true;
        }
        return true;
      }
    };
    priority_queue<vector<int>,vector<vector<int>>, mycmp> pq;
    int n=A.size();
    for (int i=0;i<=n-K;++i) {    // leaner to enumerate subarrays
      vector<int> B(A.begin()+i,A.begin()+i+K);
      pq.push(B);
    }
    vector<int> res=pq.top();
    return res;
  }
};
class Solution1 {
public: // wrong when I chose 'string', it assumes n < 10
  vector<int> largestSubarrayLenK(vector<int>& A, int K) {
    priority_queue<string> pq;
    int n=A.size();
    for (int i=0;i<=n-K;++i) {
      string s;
      for (int j=0;j<K;++j) {
        s+=to_string(A[i+j]);
      }
      pq.push(s);
    }
    vector<int> res;
    string s=pq.top();
    for (int i=0;i<s.size();++i)
      res.push_back(s[i]-'0');
    return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{1,4,3,2,5};
  for (auto n: s.largestSubarrayLenK(A1,4)) cout << n << " ";
  cout << endl;
}
