/* https://leetcode.com/problems/merge-intervals/description/
 * array, sort, lambda expression
*/
#include <bits/stdc++.h>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class Solution3 {
typedef vector<int> vi;
typedef vector<vi> vvi;
public:
  vvi merge(vvi& A) {
    map<int,int> mp;
    for (auto p: A) { // nlogn
      ++mp[p[0]];     // start reference
      --mp[p[1]];     // end reference
    }
    vvi res;
    int cnt=0;
    for (auto p: mp) {
      if (cnt && res.size()) {
        res.back()[1]=max(p.first, res.back()[1]);
      } else if (cnt==0) {
        res.push_back(vi({p.first,0}));
      }
      cnt+=p.second;  // reference counter
    }
    if (res.size()) res.back()[1]=max(res.back()[1], mp.rbegin()->first);
    return res;
  }
};
class Solution2 {
typedef vector<int> vi;
typedef vector<vi> vvi;
public:
  vvi merge(vvi& A) { // vi {start, end}
    if (A.empty()) return {};
    sort(A.begin(),A.end());    // nlogn
    vvi res(1, A[0]);
    for (int i=1; i<A.size(); ++i)
      if (A[i][0] > res.back()[1])
        res.push_back(A[i]);
      else
        res.back()[1] = max(res.back()[1], A[i][1]);
    return res;
  }
};
class Solution {
public:
	vector<Interval> merge(vector<Interval>& ints) {
		if (ints.empty()) return vector<Interval>();

		// sort by start accending order
		sort(ints.begin(),ints.end(),[](Interval a, Interval b){return a.start<b.start;});

		// merge (union) intervals once by one if there is overlap
		vector<Interval> res(1, ints[0]);
		//for (int i=0; i<ints.size(); ++i) {
		for (int i=1; i<ints.size(); ++i) {
			if (res.back().end < ints[i].start)
				res.push_back(ints[i]);
			else
				res.back().end = std::max(res.back().end, ints[i].end);
		}
		return res;
	}
};
int main(){
	Solution3 s;
	//vector<Interval> ints{{1,3},{2,6},{8,10},{15,18}};
	//vector<vector<int>> ints{{2,3},{5,5},{2,2},{3,4},{3,4}};
	//vector<vector<int>> ints{{4,5},{2,4},{4,6},{3,4},{0,0},{1,1},{3,5},{2,2}};
	vector<vector<int>> ints{{0,0},{1,1},{2,2},{2,4}};
	//vector<Interval> res = s.merge(ints);
	vector<vector<int>> res = s.merge(ints);
	//for (auto x: res) cout << x.start << "," << x.end << " ";
	for (auto x: res) cout << x[0] << "," << x[1] << " ";
	cout << endl;
}
