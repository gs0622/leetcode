#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string rankTeams(vector<string>& A) {
    int m=A.size(),n=A[0].size();
    vector<vector<int>> rank(26,vector<int>(n));
    for (int i=0;i<m;++i) for (int j=0;j<n;++j) {
      int team=A[i][j]-'A';
      ++rank[team][j];
    }
    string res=A[0];
    sort(res.begin(),res.end(),[&](char a, char b){
      int ta=a-'A',tb=b-'A';
      for (int i=0;i<n;++i) {
        if (rank[ta][i]>rank[tb][i])
          return true;
        else if (rank[ta][i]<rank[tb][i])
            return false;
        else if (rank[ta][i]==rank[tb][i]&&rank[ta][i]>0)
          return ta<tb;
      }
      return false;
    });
    return res;
  }
};
int main(){
  Solution s;
  //vector<string> A1{"ABC","ACB","ABC","ACB","ACB"};
  //vector<string> A1{"WXYZ","XYZW"};
  vector<string> A1{"BCA","CAB","CBA","ABC","ACB","BAC"};
  cout << s.rankTeams(A1) << endl;
}
