#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution2 {
  vvi v;  // O(n) space
  int x,y;
public:
  Solution2(vvi& v2d): v(v2d), x(0),y(0) {}
  int next(){
    return v[x][y++];
  }
  bool hasNext(){
    while (x<v.size() && y==v[x].size())  // tricky: y==v[x].size() tackles empty list
      ++x, y=0;
    return x<v.size();
  }
};
class Solution {
  vi v;   // O(n) space
  int id,n;
public:
  Solution(vvi& v2d) {  // O(n) time
    for (auto v1d: v2d)
      for (auto n: v1d)
        v.push_back(n);
    id=0, n=v.size();
  }
  int next() {
    return v[id++];
  }
  bool hasNext() {
    return (id<n)? true: false;
  }
};
int main(){
  vvi A1{{1,2},{3},{4,5,6}};
  //vvi A1{{1,2},{3},{},{4,5,6}};
  Solution2 s(A1);
  while (s.hasNext())
    cout << s.next() << " ";
  cout << endl;
}
