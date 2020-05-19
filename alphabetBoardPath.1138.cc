#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
  string alphabetBoardPath(string target) {
    int x=0,y=0;
    string res;
    for (auto c: target) {
      int x2=(c-'a')%5,y2=(c-'a')/5;
      res+=string(max(0,y-y2),'U');
      res+=string(max(0,y2-y),'D'); 
      res+=string(max(0,x-x2),'L'); 
      res+=string(max(0,x2-x),'R');
      res+='!'; 
    }
    return res;
  }
};
class Solution {
  vector<string> boards{"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
public:
  string alphabetBoardPath(string target) {
    string res, tmp;
    vector<int> dirs{1,0,-1,0,1};
    string dir2="RUDL";
    vector<vector<int>> visit(5,vector<int>(5,0));
    function<void(int,int,int)> helper=[&](int x,int y, int d){
      if (tmp==target) return;
      if (x<0||x>=5||y<0||y>=5||(y==5&&x>0)||visit[x][y]) return;
      //visit[x][y]==1;
      tmp+=boards[x][y];
      for (int i=0;i<4; ++i) {
        if (boards[x][y]==target[d])
          res+='!', ++d;
        int dx=dirs[i], dy=dirs[i+1];
        res+=dirs[i];
        helper(x+dx,y+dy,d);
        res.pop_back();
      }
    };
    helper(0,0,0);
    return res;
  }
};
int main(){
  Solution s;
  cout << s.alphabetBoardPath("leet") << endl;
}
