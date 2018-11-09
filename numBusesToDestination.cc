#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
		unordered_map<int, unordered_set<int>> to_route;
		for (int i=0; i<routes.size(); ++i)
			for (auto j: routes[i])
				to_route[j].insert(i);		// destination - source mapping

		queue<pair<int,int>> bfs;
		bfs.push(make_pair(S,0));
		unordered_set<int> seen{S};

		while (!bfs.empty()) {
			int stop=bfs.front().first, bus=bfs.front().second;
			bfs.pop();
			if (stop==T) return bus;
			for (auto i: to_route[stop]) {		// for each bus to this stop
				for (auto j: routes[i]) {	// consider to take bus[i], check bus[i]'s all neighbor j
					if (seen.find(j)==seen.end()) {
						seen.insert(j);
						bfs.push(make_pair(j, bus+1));
					}
				}
				routes[i].clear();
			}
		}
		return -1;
	}
};
int main(){
	Solution s;
	vector<vector<int>> nums{{1,2,7},{3,6,7}};
	cout << s.numBusesToDestination(nums, 1, 6) << endl;
}
