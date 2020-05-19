#include <bits/stdc++.h>
using namespace std;
struct Interval {
  int s, e;
  Interval(int start, int end): s(start), e(end) {}
};
class Solution {
public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>>& A) {  // nlogn, n=total intervals in A
    vector<Interval> flat, merge, res;
    for (auto e: A) for (auto i: e) // flatten 2D data to 1D: for every employee's schedule
        flat.push_back(i);

    //sort(flat.begin(),flat.end(),[](Interval a, Interval b){return a.s<b.s||(a.s==b.s&&a.e<b.e);});
    sort(flat.begin(),flat.end(),[](Interval a, Interval b){return a.s<b.s;});

    merge.push_back(flat[0]);
    for (int i=1; i<flat.size(); ++i) {   // merge
      if (flat[i].s > merge.back().e)
        merge.push_back(flat[i]);
      else
        merge.back().e = max(merge.back().e, flat[i].e);
    }
    for (auto i=1; i<merge.size(); ++i)   // compile result of the free time 
      res.push_back({merge[i-1].e, merge[i].s});
    return res;
  }
};
int main(){
  Solution s;
  vector<vector<Interval>> A1{{{1,2},{5,6}},{{1,3}},{{4,10}}};
  for (auto i: s.employeeFreeTime(A1)) cout << i.s << ", " << i.e << " ";
  cout << endl;
  vector<vector<Interval>> A2{{{1,3},{6,7}},{{2,4}},{{2,5},{9,12}}};
  for (auto i: s.employeeFreeTime(A2)) cout << i.s << ", " << i.e << " ";
  cout << endl;
}
