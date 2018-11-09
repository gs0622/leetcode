/* https://leetcode.com/problems/triangle/description/
 DP, top-down, bottom-up
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// top-down
	int minimumTotal2(vector<vector<int> > &triangle) {
		vector<int> res(triangle.size(), triangle[0][0]);	// top layer
		for (int i=1; i<triangle.size(); ++i) {			// from 2nd layer, i==layer==layer length
			for (int j=i; j>=0; --j) {
				if (j==0) res[0]+=triangle[i][j];
				else if (j==i) res[j]=triangle[i][j]+res[j-1];
				else res[j]=triangle[i][j] + min(res[j-1], res[j]);
			}
		}
		return *min_element(begin(res), end(res));
	}
	// bottom-up
	int minimumTotal1(vector<vector<int> > &triangle) {
		int n = triangle.size();
		vector<int> minlen(triangle.back());		// init w/ the bottom layer
		for (int layer=n-2; layer>=0; --layer) {	// bottom-up per layer
			for (int i=0; i<=layer; i++) {		// calculate nodes' min per layer
				// Find the lesser of its adjacent two children, and sum the current value in the triangle with it.
				minlen[i] = min(minlen[i], minlen[i+1]) + triangle[layer][i]; 
			}
		}
		return minlen[0];
	}
	// wrong because not consider nodes adjancency
	int minimumTotal(vector<vector<int>>& tri) {
		for (auto& x: tri)
			std::sort(x.begin(), x.end());
		int sum=0;
		for (auto x: tri) sum+=x[0];
		return sum;
	}
};
int main(){
	Solution s;
	vector<vector<int>> tri1{{2},{3,4},{6,5,7},{4,1,8,3}};
	cout << s.minimumTotal1(tri1) << ": " << s.minimumTotal2(tri1) << endl;
	vector<vector<int>> tri2{{-1},{2,3},{1,-1,-3}};
	cout << s.minimumTotal1(tri2) << ": " << s.minimumTotal2(tri2) << endl;
	//for (auto x: tri) {
	//	for (auto y: x) cout << y << " ";
	//	cout << endl;
	//}
}
