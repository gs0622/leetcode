#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// shortest path consider reverse thinking to change Y to adapt X by +1, /2
	int brokenCalc(int X, int Y) {
		function<int(int,int)> helper=[&](int x,int y) {
			if (x>=y) return x-y;
			if (y & 1)	// odd: last op must be dec, e.g., 4-1=3
				return 1 + helper(x, y+1);
			else		// even: last op must be double, 2*2=4
				return 1 + helper(x, y/2);
		};
		return helper(X,Y);
	}
};
int main(){
	Solution s;
	cout << s.brokenCalc(2,3) << endl;
	cout << s.brokenCalc(5,8) << endl;
	cout << s.brokenCalc(3,10) << endl;
	cout << s.brokenCalc(1024,1) << endl;
}
