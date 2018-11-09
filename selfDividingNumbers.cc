/* https://leetcode.com/problems/self-dividing-numbers/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(nm)
	vector<int> selfDividingNumbers(int left, int right) {
		int i, j;
		vector<int> res;
		for (i=left; i<=right; ++i) { // O(n) while n==intervals
			for (j=i; j>0; j/=10) { // O(m) while m==digits
				if ((j%10==0) || i%(j%10)!=0)
					break;
			}
			if (j==0) res.push_back(i);
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<int> res;
	res = s.selfDividingNumbers(1,22);
	for (auto x: res) cout << x << " ";
	cout << endl;
}
