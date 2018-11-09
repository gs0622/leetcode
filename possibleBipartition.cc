#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
		unordered_set<int> group1, group2;
		for (auto d: dislikes) {
			if (group1.empty() && group2.empty())
				group1.insert(d[0]), group2.insert(d[1]);
			else if ((group1.count(d[0]) && group1.count(d[1])) ||
				group2.count(d[0]) && group2.count(d[1]))
				return false;
			else if (group1.count(d[0]))
				group2.insert(d[1]);
			else if (group2.count(d[0]))
				group1.insert(d[1]);
			else if (group1.count(d[1]))
				group2.insert(d[0]);
			else if (group2.count(d[1]))
				group1.insert(d[0]);
		}
		return true;
	}
};
int main(){
	Solution s;
	vector<vector<int>> d1{{1,2},{1,3},{2,4}};
	vector<vector<int>> d2{{1,2},{1,3},{2,3}};
	vector<vector<int>> d3{{1,2},{2,3},{3,4},{4,5},{1,5}};
	cout << s.possibleBipartition(4,d1) << endl;
	cout << s.possibleBipartition(3,d2) << endl;
	cout << s.possibleBipartition(5,d3) << endl;
}
