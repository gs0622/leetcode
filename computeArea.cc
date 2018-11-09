#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	//
	// trick: if there is no overlap, the left/right/top/bottom are flipped.
	//
	int computeArea1(int A, int B, int C, int D, int E, int F, int G, int H) {
		int area1=(C-A)*(D-B), area2=(G-E)*(H-F);
		int left=max(A,E), bottom=max(B,F), right=min(G,C), top=min(D,H);
		int overlap=0;
		if (right>left && top>bottom)
			overlap=(right-left)*(top-bottom);
		return area1+area2-overlap;
	}
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int left = max(A,E), right = max(min(C,G), left);
		int bottom = max(B,F), top = max(min(D,H), bottom);
		return (C-A)*(D-B) - (right-left)*(top-bottom) + (G-E)*(H-F);
	}
};
int main(){
	Solution s;
	int A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2;
	cout << s.computeArea(A,B,C,D,E,F,G,H) << endl;
}
