#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<string> printVertically(string s) {
    istringstream is(s);
    vector<string> tmp, res;
    string w;
    int col=0,row;
    while (is>>w) tmp.push_back(w),col=max(col,(int)w.size()),++row;
    res.resize(col);
    for (int i=0;i<col;++i) {
      for (int j=0;j<row;++j) {
        res[i]+=(tmp[j].size()<i)? tmp[j][i]: ' ';
      }
    }
    return res;
  }
};
class Solution2 {
public:
  vector<string> printVertically(string s) {
    istringstream is(s);
    vector<string> tmp;
    string w;
    int col=0;
    while (is>>w) tmp.push_back(w),col=max(col,(int)w.size());
    int row=tmp.size();
    vector<string> res(col,string(row,0));
    for (int i=0;i<row;++i) {
      auto it=tmp[i].begin();
      for (int j=0;j<col;++j)
        res[j][i]=(it!=tmp[i].end())?*it++:' ';
    }
    for (int i=0;i<row;++i)
      for (int j=0;j<col;++j)
        res[j].erase(res[j].find_last_not_of(" \n\r\t")+1);
    return res;
  }
};
int main(){
  Solution s;
  string s1{"CONTEST IS COMING"};
  for (auto ss: s.printVertically(s1))
    cout << ss << " ";
  cout << endl;
}
