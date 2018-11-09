/*https://leetcode.com/problems/pascals-triangle-ii/description/*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> getRow(int row) {
		vector<int> res;
		int k;
		long long x=1;
		for (k=0; k<=row; ++k) {
			res.push_back((int)x);
			x = x*((row-k)/(k+1)); // key formula
		}
		return res;
	}
};
int main(){
	Solution s;
	for (auto r: s.getRow(2)) cout << r << " ";
	cout << endl;
}

