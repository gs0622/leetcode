#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(R*C), each dir steps in 112233..
	vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
		vector<vector<int>> res{{r0,c0}};
		vector<int> dirs = {0,1,0,-1,0};
		int remain=R*C-1, len=0, d=0;
		while (remain) {
			++len;
			for (int rounds=2; rounds>0; --rounds) {
				for (int i=len; i>0; --i) {
					r0+=dirs[d], c0+=dirs[d+1];
					if (r0<0||c0<0||r0>=R||c0>=C) continue;
					res.push_back({r0,c0});
					--remain;
				}
				d = (d+1)%4;
			}
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<vector<int>> res;

	res = s.spiralMatrixIII(1,4,0,0);
	for (auto p: res) cout << p[0] << ',' << p[1] << ' ';
	cout << endl;

	res =  s.spiralMatrixIII(5,6,1,4);
	for (auto p: res) cout << p[0] << ',' << p[1] << ' ';
	cout << endl;
}
