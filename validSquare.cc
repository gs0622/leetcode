/* https://leetcode.com/problems/valid-square/description/
Given the coordinates of four points in 2D space, return whether the four points could construct a square.
The coordinate (x,y) of a point is represented by an integer array with two integers.
hint: math
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		function<int(vector<int>,vector<int>)> dsq = [](vector<int> a, vector<int> b) {
			return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);	// dx^2+dy^2
		};
		unordered_set<int> s({dsq(p1,p2),dsq(p2,p3),dsq(p3,p4),dsq(p4,p1),dsq(p1,p3),dsq(p2,p4)}); // initializer list
		return !s.count(0) && s.size()==2;	// diagonalx2 + sidex4
	}
};
int main(){
	Solution s;
	//vector<int> p1{0,0}, p2{1,1}, p3{1,0}, p4{0,1};
	vector<int> p1{0,3}, p2{1,1}, p3{1,0}, p4{0,1};
	cout << s.validSquare(p1,p2,p3,p4) << endl;
}
