#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int,int>> res;
		int cur=0,cur_X, cur_H=-1,n=buildings.size();
		priority_queue<pair<int,int>> pq;	// pq of height, right
		while (cur<n || pq.size()) {
			cur_X=pq.empty()? buildings[cur][0]: pq.top().second;
			if (cur>=n || buildings[cur][0]>cur_X)
				while (pq.size() && pq.top().second <= cur_X) pq.pop();
			else {
				cur_X=buildings[cur][0];
				while (cur<n && buildings[cur][0]==cur_X)
					pq.push(make_pair(buildings[cur][2],buildings[cur][1])), ++cur;
			}
			cur_H=pq.empty()? 0: pq.top().first;
			if (res.empty() || res.back().second!=cur_H)
				res.push_back(make_pair(cur_X, cur_H));
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<pair<int,int>> res;
	vector<vector<int>> A1{{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
	res = s.getSkyline(A1);
	for (auto p: res) cout << p.first << "," << p.second << " ";
	cout << endl;
}
