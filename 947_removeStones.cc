#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
class Solution2 {
	unordered_map<int,int> mp;
	int islands=0;
	void uni(int x, int y) {
		x=find(x), y=find(y);
		if (x!=y) mp[x]=y, --islands;
	}
	int find(int x) {
		if (!mp.count(x))
			mp[x]=x, ++islands;
		if (x!=mp[x])
			mp[x]=find(mp[x]);
		return mp[x];
	}
public:
	int removeStones(vvi& stones) {
		int n=stones.size();
		for (int i=0; i<n; ++i)
			uni(stones[i][0], ~stones[i][1]);
		return n-islands;
	}
};
class Solution {
public:
	// wrong: 28 / 68 test cases passed.
	int removeStones(vvi& stones) {
		unordered_map<int,unordered_set<int>> xmp, ymp;
		for (auto s: stones) {
			xmp[s[0]].insert(s[1]);
			ymp[s[1]].insert(s[0]);
		}
		int res=0;
		for (auto s: stones) {
			if (xmp[s[0]].size()>1)
				xmp[s[0]].erase(s[1]), ++res;
			else if (ymp[s[1]].size()>1)
				ymp[s[1]].erase(s[0]), ++res;
		}
		return res;
	}
};
using namespace std;
int main(){
	Solution2 s;
	vvi A1{{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
	cout << s.removeStones(A1) << endl;
	vvi A2{{0,0},{0,2},{1,1},{2,0},{2,2}};
	cout << s.removeStones(A2) << endl;
	vvi A3{{0,0}};
	cout << s.removeStones(A3) << endl;
	vvi A4{{1,2},{1,3},{3,3},{3,1},{2,1},{1,0}};
	cout << s.removeStones(A4) << endl;
	vvi A5{{0,1},{1,0},{1,1}};
	cout << s.removeStones(A5) << endl;
}
