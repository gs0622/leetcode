/* 
hint: union find
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
	class UF {
		vector<int> id;
		int find(int p) {
			while (p!=id[p]) p=id[p];
			return p;
		}
	public:
		UF(int n=10) { for (int i=0; i<n; ++i) id.push_back(i); }
		bool isConnect(int p, int q) { return find(p) == find(q); }
		void unionTwo(int p, int q) {
			if (isConnect(p,q)) return;
			int rp = find(p), rq = find(q);
			id[rp] = rq;
		}
		int groups() {
			unordered_set<int> s;
			for (int i=0; i<id.size(); ++i)
				s.insert(find(i));
			return s.size();
		}
	};
public:
	int findCircleNum1(vector<vector<int>>& M) {
		int N=M.size(), res=0;
		vector<int> visit(N);
		function<void(int)> dfs = [&](int i){
			for (int j=0; j<N; ++j)
				if (visit[j]==0 && M[i][j]==1)
					visit[j]=1, dfs(j);
		};
		for (int i=0; i<N; ++i) {
			if (visit[i]==0)
				dfs(i), ++res;
		}
		return res;
	}
	int findCircleNum(vector<vector<int>>& M) {
		int N=M.size();
		UF u(N);
		for (int i=0; i<N; ++i) {
			for (int j=0; j<N; ++j) {
				if (i!=j && M[i][j]==1)
					u.unionTwo(i, j);
			}
		}
		return u.groups();
	}
};
int main(){
	Solution s;
	vector<vector<int>> M{{1,1,0},{1,1,1},{0,1,1}};
	cout << s.findCircleNum(M) << ": " << s.findCircleNum1(M) << endl;
}
