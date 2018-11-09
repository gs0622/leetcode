#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int findKthNumber(int m, int n, int k) {
		vector<int> table(m*n);
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				table[i*n+j] = (i+1)*(j+1);
		std::sort(table.begin(), table.end());
		return table[k-1];
	}
	int findKthNumber2(int m, int n, int k) {
		int mi, lo=0, hi=m*n;
		while (lo < hi) {
			mi = lo+(hi-lo)/2;
			int cnt = 0;
			for (int i=1;i<=m;++i)
				cnt += (mi/i <= n)? mi/i: n;
			if (cnt < k) lo=mi+1;
			else hi=mi;
		}
		return lo;
	}
};

int main(){
	Solution s;
	cout << s.findKthNumber(3,3,5) << ": ";
	cout << s.findKthNumber2(3,3,5) << endl;
	cout << s.findKthNumber(2,3,6) << ": ";
	cout << s.findKthNumber2(2,3,6) << endl;
}
