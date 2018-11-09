#include <bits/stdc++.h>
using namespace std;
class Solution {
	// backtracing
	int count(int n, vector<int>& used, int d) {
		if (d == n) return 1;
		int res = 1;
		for (int i=(d==0)? 1: 0; i<=9; ++i) {
			if (used[i]==0) {
				used[i]=1;
				res += count(n, used, d+1);
				used[i]=0;
			}
		}
		return res;
	}
public:
	int countNumbersWithUniqueDigits(int n) {
		vector<int> used(10,0);
		return count(n, used, 0);
	}
};
int main(){
	Solution s;
	cout << s.countNumbersWithUniqueDigits(2) << endl;
}
