#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> minSquare(vector<vector<int>>& pts) {
		map<int, set<int>> xmap;	// xmap to y set
		int n=pts.size(), minSide=INT_MAX;
		vector<int> res={INT_MAX,INT_MAX};
		for (int i=0; i<n; ++i)
			xmap[pts[i][0]].insert(pts[i][1]);
		for (auto it=xmap.begin(); it!=xmap.end(); ++it) {
			auto x1=it->first;
			for (auto y1=xmap[x1].begin(); y1!=xmap[x1].end(); ++y1) {
				for (auto y2=next(y1); y2!=xmap[x1].end(); ++y2) {
					auto side = *y2-*y1;
					if (side > minSide || (side == minSide && *y1 >= res[1]))
						continue;
					auto x2 = x1 + side;
					if (xmap[x2].count(*y1) && xmap[x2].count(*y2))
						minSide = side, res = {x1, *y1};
				}
			}
		}
		cout << minSide*minSide << endl;
		return res;
	}
	vector<int> maxSquare(vector<vector<int>>& pts) {
		map<int, set<int>> xmap;	// xmap to y set
		int n=pts.size(), maxSide=0;
		vector<int> res={0,0};
		for (int i=0; i<n; ++i)
			xmap[pts[i][0]].insert(pts[i][1]);
		for (auto it=xmap.begin(); it!=xmap.end(); ++it) {
			auto x1=it->first;
			for (auto y1=xmap[x1].begin(); y1!=xmap[x1].end(); ++y1) {
				for (auto y2=next(y1); y2!=xmap[x1].end(); ++y2) {
					auto side = *y2-*y1;
					if (side < maxSide || (side == maxSide && *y1 >= res[1]) )
						continue;
					auto x2=x1+side;
					if (xmap[x2].count(*y1) && xmap[x2].count(*y2))
						maxSide=side, res = {x1, *y1};
				}
			}
		}
		cout << maxSide*maxSide << endl;
		return res;
	}
	// O(n^4)
	int minArea1(vector<pair<int,int>>& pts) {
		int n=pts.size();
		function<int(pair<int,int>,pair<int,int>)> distSq=[](pair<int,int> a, pair<int,int> b){
			int dx = b.first-a.first, dy=b.second-a.second;
			return dx*dx+dy*dy;	// square of distance
		};
		int res=INT_MAX;
		for (auto i=0; i<n; ++i) for (auto j=i+1; j<n; ++j) for (auto k=j+1; k<n; ++k) for (auto l=k+1; l<n; ++l) {
			set<int> dist;			// ordered hashset for width-height-diag, or width-width-diag
			int d12=distSq(pts[i],pts[j]);
			int d23=distSq(pts[j],pts[k]);
			int d34=distSq(pts[k],pts[l]);
			int d41=distSq(pts[l],pts[i]);
			int d13=distSq(pts[i],pts[k]);
			int d24=distSq(pts[j],pts[l]);
			dist.insert(d12);
			dist.insert(d23);
			dist.insert(d34);
			dist.insert(d41);
			dist.insert(d13);
			dist.insert(d24);
			// Pythagorean checks for rectangle and square
			if (dist.size()==3) {
				auto it=dist.begin();
				int w=*it, h=*(++it), diag=*(++it);
				if (w+h==diag)
					res=min(res,(int)sqrt(w*h));
			}
			if (dist.size()==2) {
				auto it=dist.begin();
				int w=*it,diag=*(++it);
				if (w+w==diag)
					res=min(res,(int)sqrt(w*w));
			}
		}
		//return res;
		return res==INT_MAX?0:res;
	}
	// O(n^2), wrong
	int minArea(vector<pair<int,int>>& pts) {
		stable_sort(begin(pts), end(pts), [](pair<int,int> x, pair<int,int> y){
			return x.first < y.first || (x.first==y.first && x.second < y.second); });	// sort x then y
		int res=INT_MAX;
		for (int i=1; i<pts.size(); ++i) {				// sweep x from left to  right
			if (pts[i].first == pts[i-1].first) {			// find 1st two points in same x
				for (int j=i+2; j<pts.size(); ++j) {
					if (pts[j].first == pts[j-1].first) {	// find 2nd two points in same x
						if (pts[i].second == pts[j].second &&
							pts[i-1].second == pts[j-1].second) {	// if 4 points forms rectangle
								res = min(res, (pts[j].first-pts[i].first) * (pts[i].second-pts[i-1].second));
							}
					}
				}
			}
		}
		return res==INT_MAX?0:res;
	}
};
int main(){
	Solution s;
	vector<pair<int,int>> pts1{{4,3},{4,1},{4,2},{1,3},{1,1},{1,2}};
	cout << s.minArea1(pts1) << endl;
	vector<pair<int,int>> pts2{{1,1},{1,1},{1,1},{1,1}};
	cout << s.minArea1(pts2) << endl;
	vector<pair<int,int>> pts3{{4,3},{5,1},{5,4},{1,1},{1,4},{2,4},{4,2},{6,4},{4,6}};
	cout << s.minArea1(pts3) << endl;

	vector<int> res;
	vector<vector<int>> pts4{{1,1},{3,1},{5,1},{1,3},{3,3},{5,3}};
	res = s.maxSquare(pts4);
	cout << res[0] << ',' << res[1] << endl;

	vector<vector<int>> pts5{{1,1},{3,1},{5,1},{1,3},{3,3},{5,3},{1,5},{5,5},{3,5},{7,5}};
	res = s.minSquare(pts5);
	cout << res[0] << ',' << res[1] << endl;
	res = s.maxSquare(pts5);
	cout << res[0] << ',' << res[1] << endl;
}
