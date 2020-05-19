#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(log(y))
	int leastOpsExpressTarget1(int x, int y) {
		int pos=0,neg=0,k,pos2,neg2,cur;
		for (k=0; y>0; ++k, y/=x) {
			cur = y % x;
			if (k > 0) {
				pos2 = min(cur * k + pos, (cur + 1) * k + neg);
				neg2 = min((x - cur) * k + pos, (x - cur - 1) * k + neg);
				pos = pos2, neg = neg2;
			} else {	// k==0
				pos = cur * 2;
				neg = (x - cur) * 2;
			}
		}
		return min(pos, k + neg) - 1;
	}
	// wrong
	int leastOpsExpressTarget(int x, int target) {
		int res=0;
		function<int(int,int)> dfs=[&](int y, int d) {
			if (y==0) return INT_MAX;
			if (y==target) return d;
			++d;
			int r = dfs(y+x, d);
			r = min(r, dfs(y-x,d));
			r = min(r, dfs(y*x,d));
			r = min(r, dfs(y/x,d));
			return r;
		};
		res = dfs(x,0);
		return res;
	}
};
int main(){
	Solution s;
	cout << s.leastOpsExpressTarget1(3,19) << endl;
}
