/* https://leetcode.com/problems/find-right-interval/description/
*/
#include <climits>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution2 {
public:
	vector<int> findRightInterval(vector<vector<int>>& intervals) {
    int n=intervals.size();
    map<int,int> mp;
    for (int i=0;i<n;++i) mp[intervals[i][0]]=i;  // key 'start' to associate w/ index
    vector<int> res(n,-1);
    for (int i=0;i<n;++i) {
      auto it=mp.lower_bound(intervals[i][1]);    // find lower_bound of 'end'
      if (it!=mp.end()) res[i]=it->second;
    }
    return res;
  }
};
/*
 * Definition for an interval.
 */
struct Interval {
int start;
int end;
Interval() : start(0), end(0) {}
Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<int> findRightInterval(vector<Interval>& x) {
		int n=x.size();
		map<int,int> mapS;		// start-index map w/ lower_bound method
		vectora<int> res(n,-1);
		for (int i=0; i<n; ++i)		// O(n)
			mapS[x[i].start]=i;
		for (int i=0; i<n; ++i) {
			auto it = mapS.lower_bound(x[i].end);
			if (it != mapS.end()) res[i] = it->second;
		}
		return res;
	}
	vector<int> findRightInterval1(vector<Interval>& x) {
		int sz = x.size();
		map<int,int> m;
		vector<int> ans(sz, -1);
		for (int i=0; i<sz; ++i) // hash start in order
			m[x[i].start] = i;
		for (int i=0; i<sz; ++i) { // find lower_bound right
			auto it = m.lower_bound(x[i].end);
			if (it != m.end())
				ans[i] = it->second;
		}
		return ans;
	}
	vector<int> findRightInterval2(vector<Interval>& intervals) {
		int sz = intervals.size();
		vector<int> ans(sz, -1);
		for (int i=0; i<sz; ++i) {
			int diff = INT_MAX;
			for (int j=0; j<sz; ++j) {
				int diff2 = intervals[j].start - intervals[i].end;
				if (diff2 >= 0) {
					if (diff2 < diff)
						ans[i] = j, diff = diff2;
				}
			}
		}
		return ans;
	}
};
void test(vector<Interval>& x);
void test1();
void test2();
void test3();
int main(){
	test1();
	test2();
	test3();
}
void test(vector<Interval>& x){
	Solution s;
	vector<int> ret = s.findRightInterval(x);
	for (auto y: ret) cout << y << " ";
	cout << endl;
}
void test1(){
	vector<Interval> x{{1,2}};
	test(x);
}
void test2(){
	vector<Interval> x{{3,4},{2,3},{1,2}};
	test(x);
}
void test3(){
	vector<Interval> x{{1,4},{2,3},{3,4}};
	test(x);
}
