#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> smallestRange(vector<vector<int>>& nums) {
		typedef vector<int>::iterator vi;
		struct cmp {
			bool operator()(pair<vi,vi> p1, pair<vi,vi> p2) {
				return *p1.first > *p2.first;
			}
		};
		priority_queue<pair<vi,vi>, vector<pair<vi,vi>>, cmp> pq;	// think about pair of iterator vs tuple
		int lo=INT_MAX, hi=INT_MIN;

		for (auto &r: nums) {
			lo=min(lo, r[0]), hi=max(hi, r[0]);
			pq.push({r.begin(), r.end()});
		}

		vector<int> res{lo, hi};
		while (true) {
			auto p=pq.top(); pq.pop();
			++p.first;
			if (p.first == p.second)
				break;
			pq.push(p);
			lo = *pq.top().first;
			hi = max(hi, *p.first);
			if (hi-lo < res[1]-res[0])
				res={lo,hi};
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<vector<int>> nums1{{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
	vector<int> res = s.smallestRange(nums1);
	cout << res[0] << " " << res[1] << endl;
}
