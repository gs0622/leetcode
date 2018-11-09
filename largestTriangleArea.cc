/* https://leetcode.com/problems/largest-triangle-area/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// https://www.mathopenref.com/coordtrianglearea.html
	double largestTriangleArea(vector<vector<int>>& p) {
		double res = 0;
		for (auto &i : p) for (auto &j : p) for (auto &k : p)
			res = max(res, 0.5 * abs(i[0]*j[1] + j[0]*k[1] + k[0]*i[1] - j[0]*i[1] - k[0]*j[1] - i[0]*k[1]));
		return res;
	}
};
int main(){}
