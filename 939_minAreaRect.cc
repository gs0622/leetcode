/* https://leetcode.com/problems/minimum-area-rectangle/description/

Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points,
with sides parallel to the x and y axes.

If there isn't any rectangle, return 0.
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
class Solution2 {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int,set<int>> mp;
        int res=INT_MAX;
        for (auto p: points)
            mp[p[0]].insert(p[1]);     // sort x then y: O(nlognlongn)
        for (auto x1=mp.begin(); x1!=mp.end(); ++x1) {  // O(n)
            for (auto x2=next(x1); x2!=mp.end(); ++x2) {
                // enumerate all y pairs per x1: O(n^2)
                for (auto y1=x1->second.begin(); y1!=x1->second.end(); ++y1) {
                    for (auto y2=next(y1); y2!=x1->second.end(); ++y2) {
                        if (x2->second.count(*y1) && x2->second.count(*y2))
                            res=min(res, (x2->first-x1->first)*(*y2-*y1));
                    }
                }
            }
        }
        return res==INT_MAX? 0: res;
    }
};
class Solution {
public:
	int minAreaRect(vvi& points) {
		map<int,set<int>> mp;
		for (auto p: points) mp[p[0]].insert(p[1]);	// x-planes
		int res=INT_MAX;
		for (auto p: mp) {
			int x1=p.first;
			for (auto y1=p.second.begin(); y1!=p.second.end(); ++y1) {
				for (auto y2=next(y1); y2!=p.second.end(); ++y2) {
					auto side = *y2-*y1;	// candidate side length
					auto x2 = x1+side;
					if (mp[x2].count(*y1) && mp[x2].count(*y2))
						res=min(res,side);
				}
			}
		}
		return res*res;
	}
};
int main(){
	Solution2 s;
	vvi A1{{1,1},{1,3},{3,1},{3,3},{2,2}};
	cout << s.minAreaRect(A1) << endl;
}
