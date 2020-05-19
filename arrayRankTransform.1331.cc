#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> arrayRankTransform(vector<int>& A) {
    int n=A.size();
    vector<pair<int,int>> mp;
    for (int i=0;i<n;++i)
      mp.push_back({A[i],i}); // {key,idx}
    sort(mp.begin(),mp.end());

    int rank=1;
    for (auto it=mp.begin(); it!=mp.end(); ++it) {
      if (it==mp.begin())
        A[it->second]=rank;
      else
        A[it->second]=(it->first==(it-1)->first)? rank: ++rank;
    }
    return A;
  }
};
class Solution3 {
public:
  vector<int> arrayRankTransform(vector<int>& A) {
    int n=A.size();
    vector<int> rank(n,1);
    for (int i=0;i<n;++i) {
      for (int j=0;j<n;++j) {
        if (i==j) continue;
        if (A[j]<A[i]) ++rank[i];
      }
    }
    return rank;
  }
};
class Solution2 {
public:
  vector<int> arrayRankTransform(vector<int>& A) {
    int n=A.size();
    vector<int> B(A);
    sort(B.begin(),B.end());
    unordered_map<int,int> mp;
    for (auto b: B)
      mp.emplace(b,mp.size()+1);
    for (auto& a: A)
      a=mp[a];
    return A;
  }
};
class Solution1 {
public:
  vector<int> arrayRankTransform(vector<int>& A) {  // O(n^2) time
    int n=A.size();
    vector<int> B=A;
    for (int i=0;i<n;++i) {
      int rank=1;
      for (int j=0;j<n;++j)
        if (B[i]>B[j]) ++rank;
      A[i]=rank;
    }
    return A;
  }
};
int main(){
  Solution s;
  vector<int> A1{40,10,20,30};
  for (auto n: s.arrayRankTransform(A1)) cout << n << " ";
  cout << endl;
}
