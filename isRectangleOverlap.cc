/* https://leetcode.com/problems/rectangle-overlap/discuss/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// 1D-overlap: L1<R2 && L2<R1 in line, expand to 2D as plane
	bool isRectangleOverlap1(vector<int>& rec1, vector<int>& rec2) {
		//rec1 {L1x,L1y,R1x,R1y}, rec2{L2x,L2y,R2x,R2y}
		return rec1[0]<rec2[2] && rec2[0]<rec1[2] &&	// x-plane
			rec1[1]<rec2[3] && rec2[1]<rec1[3];	// y-plane
	}
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		vector<int> ovl(4);
		ovl[0]=max(rec1[0],rec2[0]);	// x
		ovl[1]=max(rec1[1],rec2[1]);	// y
		ovl[2]=min(rec1[2],rec2[2]);	// x
		ovl[3]=min(rec1[3],rec2[3]);	// y
		return (ovl[2]>ovl[0]) && (ovl[3]>ovl[1]);
	}
};
int main(){
	Solution s;
	vector<int> a1{0,0,2,2}, a2{1,1,3,3};
	vector<int> b1{0,0,1,1}, b2{1,0,2,1};
	vector<int> c1{0,0,1,1}, c2{2,2,3,3};
	vector<int> d1{5,15,8,18}, d2{0,3,7,9};
	cout << s.isRectangleOverlap(a1,a2) << ' ' << s.isRectangleOverlap1(a1,a2) <<  endl;
	cout << s.isRectangleOverlap(b1,b2) << ' ' << s.isRectangleOverlap1(b1,b2)  << endl;
	cout << s.isRectangleOverlap(c1,c2) << ' ' << s.isRectangleOverlap1(c1,c2) << endl;
	cout << s.isRectangleOverlap(d1,d2) << ' ' << s.isRectangleOverlap1(d1,d2) << endl;
}
