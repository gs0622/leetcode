#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string stringShift(string s, vector<vector<int>>& A) {
    int m=s.size(),k=0;
    for (auto a: A)
      k+=a[0]?a[1]:-a[1];
    if (k<0) {
      k=-k;
      rotate(s.begin(),s.begin()+(k%m),s.end());
    } else if (k>0) {
      reverse(s.begin(),s.end());
      reverse(s.begin(),s.begin()+(k%m));
      reverse(s.begin()+(k%m),s.end());
    }
    return s;
  }
};
class Solution1 {
public:
    string stringShift(string s, vector<vector<int>>& A) {
      int m=s.size(),n=A.size();
      for (int i=0;i<n;++i) {
        int k=A[i][1];
        if (A[i][0]==0) {
          rotate(s.begin(),s.begin()+(k%m),s.end());
        } else {
          reverse(s.begin(),s.end());
          reverse(s.begin(),s.begin()+(k%m));
          reverse(s.begin()+(k%m),s.end());
        }
      }
      return s;
    }
};
int main(){
  Solution s;
  //vector<vector<int>> A1{{0,1},{1,2}};
  //cout << s.stringShift("abc",A1) << endl;
  vector<vector<int>> A1{{0,7},{1,7},{1,0},{1,3},{0,3},{0,6},{1,2}};
  cout << s.stringShift("wpdhhcj",A1) << endl;
}
