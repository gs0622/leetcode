#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
class Solution {
public:
  // Greedy Solution, O(1) Space, by lee215
  int videoStitching(vector<vector<int>>& clips, int T) {
    sort(clips.begin(),clips.end(),[](vector<int>& a, vector<int>& b){ return a[0]<b[0]; });
    int res=0, e1=-1, e2=0;
    for (auto c: clips) {
      if (e2>=T || c[0]>e2) break;
      else if (e1 < c[0] && c[0] <= e2)
        e1=e2, ++res;
      e2=max(e2,c[1]);
    }
    return e2>=T? res: -1;
  }
};
int main(){
  Solution s;
  vvi C1{{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}};
  cout << s.videoStitching(C1,10) << endl;
}
