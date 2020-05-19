#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> processQueries(vector<int>& A, int m) {
    vector<int> P(m),res;
    iota(P.begin(),P.end(),1);
    for (auto a: A) {
      auto it=find(P.begin(),P.end(),a);  // query
      res.push_back(distance(P.begin(),it));
      while (it!=P.begin())
        swap(*it,*(it-1)),--it;
    }
    return res;
  }
};
class Solution1 {
public:
  vector<int> processQueries(vector<int>& A, int m) {
    int n=A.size();
    vector<int> res;
    deque<int> P(m);
    for (int i=0;i<m;++i) {
      P[i]=i+1;
    }
    for (auto a: A) {
      for (int i=0;i<m;++i) {
        if (P[i]==a) {
          res.push_back(i);
          P.erase(P.begin()+i);
          P.push_front(a);
          break;
        }
      }
    }
    return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{3,1,2,1};
  for (auto n: s.processQueries(A1,5)) cout << n << " ";
  cout << endl;
}
