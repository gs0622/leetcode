#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool splitArraySameAverage(vector<int>& A) {
		int n=A.size(), m=n/2, tSum=accumulate(begin(A), end(A), 0);
		// early pruning
		bool ans = false;
		for (int i=1; i<=m && !ans; ++i)
			if (tSum*i%n==0) ans = true;
		if (!ans) return false;
		vector<unordered_set<int>> sums(m+1);
		sums[0].insert(0);
		for (int num: A) {
			for (int i=m; i>=1; --i)
				for (const int t: sums[i-1])
					sums[i].insert(t+num);
		}
		for (int i=1; i<=m; ++i)
			if (tSum*i%n==0 && sums[i].find(tSum*i/n) != sums[i].end())
				return true;
		return false;
	}
};
int main(){
	Solution s;
	vector<int> nums{1,2,3,4,5,6,7,8};
	cout << s.splitArraySameAverage(nums) << endl;
}
