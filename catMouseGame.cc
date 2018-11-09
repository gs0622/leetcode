#include <bits/stdc++.h>
using namespace std;
class Solution {
	vector<vector<int>> parents(vector<vector<int>>& graph, int m, int c, int t) {
		vector<vector<int>> res;
		if (t==2) {
			for (int m2: graph[m])
				res.push_back({m2, c, 3-t});
		} else {
			for (int c2: graph[c]) if (c2 > 0)
				res.push_back({m, c2,3-t});
		}
		return res;
	}
public:
	int catMouseGame(vector<vector<int>>& graph) {
		int n = graph.size();
		const int DRAW=0, MOUSE=1, CAT=2;
		auto color = new int[50][50][3];
		auto degree = new int[50][50][3];
		for (int m=0; m<n; ++m) {
			for (int c=0; c<n; ++c) {
				degree[m][c][1]=graph[m].size();
				degree[m][c][2]=graph[c].size();
				for (int x: graph[c]) if (x==0) {
					degree[m][c][2]--;
					break;
				}
			}
		}
		queue<vector<int>> q;
		for (int i=0; i<n; ++i) {
			for (int j=1; j<=2; ++j) {
				color[0][i][j]=MOUSE;
				q.push({0,i,j,MOUSE});
				if (i>0) {
					color[i][i][j]=CAT;
					q.push({i,i,j,CAT});
				}
			}
		}
		while (q.size()) {
			auto node = q.front(); q.pop();
			int i=node[0],j=node[1],t=node[2],c=node[3];
			for (auto parent: parents(graph, i, j, t)) {
				int i2=parent[0],j2=parent[1],t2=parent[2];
				if (color[i2][j2][t2]==DRAW) {
					if (t2==c) {
						color[i2][j2][t2]=c;
						q.push({i2,j2,t2,c});
					} else {
						degree[i2][j2][t2]--;
						if (degree[i2][j2][t2]==0) {
							color[i2][j2][t2]=3-t2;
							q.push({i2,j2,t2,3-t2});
						}
					}
				}
			}
		}
		return color[1][2][1];
	}
};
int main(){
	Solution s;
	vector<vector<int>> G1{{2,5},{3},{0,4,5},{1,4,5},{2,3},{0,2,3}};
	cout << s.catMouseGame(G1) << endl;
}
