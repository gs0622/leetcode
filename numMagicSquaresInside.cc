/* https://leetcode.com/problems/magic-squares-in-grid/description/

A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).

hint: center is 5, along w/ 43816729
e.g.
      4 3 8
      9 5 1
      2 7 6
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int numMagicSquaresInside(vector<vector<int>>& G) {
		string mag1{"4381672943816729"}, mag2{"9276183492761834"};
		if (G.size()<3 || (!G.empty() && G[0].size()<3)) return 0;
		int m=G.size(), n=G[0].size(), res=0;
		for (int i=0; i<=m-3; ++i) {
			for (int j=0; j<=n-3; ++j) {
				if (G[i+1][j+1]!=5) continue;
				string s="";
				s+=to_string(G[i][j]);
				s+=to_string(G[i][j+1]);
				s+=to_string(G[i][j+2]);
				s+=to_string(G[i+1][j+2]);
				s+=to_string(G[i+2][j+2]);
				s+=to_string(G[i+2][j+1]);
				s+=to_string(G[i+2][j]);
				s+=to_string(G[i+1][j]);
				if (mag1.find(s) == string::npos && mag2.find(s) == string::npos)
					continue;
				++res;
			}
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<vector<int>> G1{{4,3,8,4},{9,5,1,9},{2,7,6,2}};
	vector<vector<int>> G2{{10,3,5},{1,6,11},{7,9,2}};
	vector<vector<int>> G3{{3,10,2,3,4},{4,5,6,8,1},{8,8,1,6,8},{1,3,5,7,1},{9,4,9,2,9}};
	vector<vector<int>> G4{{8,0,7,4,3,2},{1,10,4,4,3,8},{8,5,2,9,5,1},{6,0,9,2,7,6},{9,0,6,9,5,1},{4,2,1,4,3,8}};
	//cout << s.numMagicSquaresInside(G1) << endl;
	//cout << s.numMagicSquaresInside(G2) << endl;
	//cout << s.numMagicSquaresInside(G3) << endl;
	cout << s.numMagicSquaresInside(G4) << endl;
}
