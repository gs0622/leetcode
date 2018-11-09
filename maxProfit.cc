#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& p) {
		if (p.size()<2) return 0;
		int min_p=INT_MAX, ans=0, n=p.size();
		for (auto x: p) {
			min_p = std::min(x, min_p);
			ans = std::max(x-min_p, ans);
		}
		return ans;
	}
	int maxProfit2(vector<int>& p) {
		if (p.size()<2) return 0;
		int i, j, n=p.size();
		vector<int> d(n,0);
		for (i=n-1;i>=1;--i) {
			for (j=i-1; j>=0; --j)
				d[i]=std::max(p[i]-p[j], d[i]);
		}
		return *std::max_element(d.begin(), d.end());
	}
};

int main(){
	Solution s;
	vector<int> p{7, 1, 5, 3, 6, 4};
	cout << s.maxProfit(p) << endl;
}
