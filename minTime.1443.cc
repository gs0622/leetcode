#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minTime(int n, vector<vector<int>>& A, vector<bool>& B) {
    unordered_map<int,vector<int>> mp;  // adj list
    unordered_set<int> st;
    for (auto a: A) {
      mp[a[0]].push_back(a[1]);
      mp[a[1]].push_back(a[0]); // undirected graph
    }
    function<int(int)> dfs=[&](int cur){
      if (st.count(cur))
        return 0;
      st.insert(cur);
      if (mp.count(cur)==0) {
        //cout << "A: " << cur << ":" << B[cur]*2 << endl;
        return B[cur]*2;
      }
      int cost=0;
      for (auto nxt: mp[cur])
        cost+=dfs(nxt);
        //cout << "B: " << cur << ":" << cost << endl;
      if (cur!=0)
        return (cost==0? B[cur]*2: 0) + (cost>0? 2+cost: 0);
      return cost;
    };
    return dfs(0);
  }
};
int main(){
  Solution s;
  //vector<vector<int>> A1{{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
  //vector<bool> B1{false,false,true,false,true,true,false};
  //vector<bool> B1{false,false,true,false,false,true,false};
  //cout << s.minTime(7,A1,B1) << endl;
  vector<vector<int>> A1{{0,2},{0,3},{1,2}};
  vector<bool> B1{0,1,0,0};
  cout << s.minTime(4,A1,B1) << endl;
}
