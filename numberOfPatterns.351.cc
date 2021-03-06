/*
Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.
Rules for a valid pattern:
Each pattern must connect at least m keys and at most n keys.
All the keys must be distinct.
If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
The order of keys used matters.

| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int numberOfPatterns(int m, int n) {
    int skip[10][10]={};
    skip[1][3]=skip[3][1]=2; 
    skip[7][9]=skip[9][7]=8; 
    skip[1][7]=skip[7][1]=4; 
    skip[3][9]=skip[9][3]=6; 
    skip[2][8]=skip[8][2]=skip[1][9]=skip[9][1]=skip[3][7]=skip[7][3]=skip[4][6]=skip[6][4]=5; 
    int res=0;
    bool visit[10]={};
    function<int(int,int)> helper=[&](int cur, int left){ // backtracing helper
      if (left==0) return 1;  // picked by caller, so +1
      visit[cur]=true;
      for (int i=1;i<=9;++i) {
        //pick next
        if (!visit[i] && (skip[cur][i]==0 || visit[skip[cur][i]]))
          res+=helper(i,left-1);
      }
      visit[cur]=false;
    };
    for (int i=m;i<=n;++i) {
      for (int j=1;j<=9;++j)
        res+=helper(j,i);
    }
    return res;
  }
};
int main(){
}
