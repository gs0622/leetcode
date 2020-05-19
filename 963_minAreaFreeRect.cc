#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
class Solution {
	long dist(vi& a, vi& b) {
		int dx=b[0]-a[0], dy=b[1]-a[1];
		return (long)dx*dx+dy*dy;
	}
public:
	// O(n^2) using diagonal and center as key to rearrange points list
	double minAreaFreeRect2(vvi& pts, double res=0) {
		int n=pts.size();
		unordered_map<string,vvi> mp;
		for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
			long d=dist(pts[i],pts[j]);
			double x=(pts[i][0]+pts[j][0])/2.0, y=(pts[i][1]+pts[j][1]);
			mp[to_string(d)+","+to_string(x)+","+to_string(y)].push_back({i,j});	// diagonal,centerX,centerY: pts[i], pts[j]
		}
		for (auto it: mp) {
			if (it.second.size()<2) continue;
			vvi pts2=it.second;
			int m=pts2.size();
			for (int i=0; i<m; ++i) for (int j=i+1; j<m; ++j) {
				int p1=pts2[i][0], p2=pts2[i][1], p3=pts2[j][0];
				long d13=dist(pts[p1],pts[p3]), d23=dist(pts[p2],pts[p3]);
				double area=sqrt(d13*d23);
				if (res==0 || res>area) res=area;
			}
		}
		return res;
	}
	// O(n^3): enumerate 3 points to get the 4th
	double minAreaFreeRect1(vvi& pts, double res=0) {
		int n=pts.size();
		unordered_set<string> st;
		for (auto p: pts)
			st.insert(to_string(p[0])+","+to_string(p[1]));
		for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) for (int k=0; k<n; ++k) {
			if (i==j || j==k || i==k) continue;
			if ((pts[j][0]-pts[i][0])*(pts[k][0]-pts[i][0]) + (pts[j][1]-pts[i][1])*(pts[k][1]-pts[i][1])!=0) continue;
			int x4=pts[k][0]+pts[j][0]-pts[i][0], y4=pts[k][1]+pts[j][1]-pts[i][1];	// tricky: why?
			if (st.count(to_string(x4)+","+to_string(y4))==0) continue;
			double area = sqrt(dist(pts[i],pts[j])*dist(pts[i],pts[k]));
			if (res==0 || res > area) res=area;
		}
		return res;
	}
	// O(n^3): enumerate 3 points to get the 4th
	double minAreaFreeRect(vvi& pts, double res=0) {
		int n=pts.size();
		unordered_set<string> st;
		for (auto p: pts) st.insert(to_string(p[0])+","+to_string(p[1]));
		for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) for (int k=0; k<n; ++k) {
			if (i==j || j==k || i==k) continue;
			double a=dist(pts[i], pts[j]), b=dist(pts[j],pts[k]), c=dist(pts[k],pts[i]);
			if (a+b!=c) continue;
			int x4=pts[i][0]+pts[k][0]-pts[j][0], y4=pts[i][1]+pts[k][1]-pts[j][1];	// tricky: why?
			if (st.count(to_string(x4)+","+to_string(y4))==0) continue;
			double area = sqrt(a*b);
			if (res==0 || res > area) res=area;
		}
		return res;
	}
};
int main(){
	Solution s;
	vvi P1{{1,2},{2,1},{1,0},{0,1}};
	cout << s.minAreaFreeRect2(P1) << endl;
	vvi P2{{0,3},{1,2},{3,1},{1,3},{2,1}};
	cout << s.minAreaFreeRect2(P2) << endl;
	vvi P3{{3,1},{1,1},{0,1},{2,1},{3,3},{3,2},{0,2},{2,3}};
	cout << s.minAreaFreeRect2(P3) << endl;
	vvi P4{{24420,16685},{20235,25520},{14540,20845},{20525,14500},{16876,24557},{24085,23720},{25427,18964},{21036,14573},{24420,23315},{22805,24760},{21547,25304},{16139,23952},{21360,14645},{24715,17120},{19765,25520},{19388,25491},{22340,25005},{25520,19765},{25365,21320},{23124,15443},{20845,14540},{24301,16532},{16685,24420},{25100,17875},{22125,25100},{15699,23468},{14592,21131},{25460,19155},{17837,25084},{23468,24301},{25460,20845},{18453,25304},{21131,14592},{22805,15240},{19475,25500},{15443,23124},{25355,21360},{15285,22880},{20000,25525},{24085,16280},{22163,25084},{22880,15285},{14916,22163},{16280,24085},{24875,17400},{22600,24875},{14573,21036},{25427,21036},{17120,24715},{25500,19475}};
	cout << s.minAreaFreeRect2(P4) << endl;
}
