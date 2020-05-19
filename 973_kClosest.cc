#include <bits/stdc++.h>
using namespace std;
class Solution {
	static bool cmp(vector<int> a, vector<int> b) { return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1]; }
	static int cmp1(vector<int> a, vector<int> b) { return a[0]*a[0]+a[1]*a[1] - b[0]*b[0]+b[1]*b[1]; }
	int helper(vector<vector<int>>& pts, int lo, int hi) {
		auto pivot=pts[lo];
		while (lo<hi) {
			while (lo<hi && cmp1(pts[hi],pivot)>=0) --hi;
			pts[lo]=pts[hi];
			while (lo<hi && cmp1(pts[lo],pivot)<=0) ++lo;
			pts[hi]=pts[lo];
		}
		pts[lo]=pivot;
		return lo;
	}
public:
	vector<vector<int>> kClosest3(vector<vector<int>>& points, int K) {
		int n=points.size(), lo=0, hi=n-1;
		while (lo<=hi) {
			int mi=helper(points, lo, hi);
			if (mi==K) break;
			else if (mi<K) lo=mi+1;
			else hi=mi-1;
		}
		return vector<vector<int>>(points.begin(), points.begin()+K);
	}
	// O(n)
	// advantage: efficient
	// disadvantage:
	vector<vector<int>> kClosest2(vector<vector<int>>& points, int K) {
                int n=points.size(), lo=0, hi=n-1;
                while (lo<hi) {
                        auto it = partition(points.begin()+lo, points.begin()+hi, [&](vector<int> p){
                                return cmp(p, points[hi]);      // points[hi] is pivot
                        });
                        int mi = distance(points.begin(), it);
                        swap(points[hi],points[mi]);
                        if (mi==K) break;
                        else if (mi<K) lo=mi+1;
                        else hi=mi-1;
                }
                return vector<vector<int>>(points.begin(), points.begin()+K);
	}
	// O(nlogK) reduce inner loop from logn to logK, non-sorted
	// advatage: online streaming data
	// disadvantage: not the most efficient solution
	vector<vector<int>> kClosest1(vector<vector<int>>& points, int K) {
		priority_queue<vector<int>> pq;	// maxheap
		for (auto p: points) {		// O(n)
			pq.push(p);		
			if (pq.size()>K) pq.pop();	// the top one must not include, and make the heap in logK time
		}
		vector<vector<int>> res;
		while (pq.size()) res.push_back(pq.top()), pq.pop();
		return res;
	}
	// O(nlogn), naive, sorted
	// advantages: short, disadvantage: offline which require to touch every points
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		sort(points.begin(), points.end(), cmp);
		vector<vector<int>> res(points.begin(), points.begin()+K);
		return res;
	}
};
int main(){
	Solution s;
	vector<vector<int>> P1{{1,3},{-2,2}};
	for (auto p: s.kClosest3(P1, 1)) cout << p[0] << "," << p[1] << " ";
	cout << endl;
	vector<vector<int>> P2{{3,3},{5,-1},{-2,4}};
	for (auto p: s.kClosest3(P2, 2)) cout << p[0] << "," << p[1] << " ";
	cout << endl;
	vector<vector<int>> P3{{10,-2},{2,-2},{10,10},{9,4},{-8,1}};
	for (auto p: s.kClosest3(P3, 4)) cout << p[0] << "," << p[1] << " ";
	cout << endl;
	vector<vector<int>> P4{{5,4},{-6,5},{4,6}};
	for (auto p: s.kClosest3(P4, 2)) cout << p[0] << "," << p[1] << " ";
	cout << endl;
}
