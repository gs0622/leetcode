/* https://leetcode.com/problems/reaching-points/description/
A move consists of taking a point (x, y) and transforming it to either (x, x+y) or (x+y, y).

Given a starting point (sx, sy) and a target point (tx, ty), return True if and only if a sequence of moves exists to transform the point (sx, sy) to (tx, ty). Otherwise, return False.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(logN) where N = max(tx,ty).
	// First line:
	// if 2 target points are still bigger than 2 starting point, we reduce target points.
	// Second line:
	// check if we reduce target points to (x, y+kx) or (x+ky, y)
	bool reachingPoints(int sx, int sy, int tx, int ty) {
		while (sx<tx && sy<ty)
			if (tx<ty) ty%=tx; else tx%=ty;
		return (sx==tx && (ty-sy)%sx==0) || (sy==ty && (tx-sx)%sy==0);
	}
};
int main(){
	Solution s;
	cout << s.reachingPoints(1,1,3,5) << endl;
	cout << s.reachingPoints(1,1,2,2) << endl;
}
