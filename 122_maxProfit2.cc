#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& p) {
		if (p.size()==0) return 0;
		int res = 0;
		for (int i=0; i<p.size()-1; ++i)
			res += (p[i+1]-p[i])>0? p[i+1]-p[i]:0;
		return res;
	}
};

int main(){
	Solution s;
	vector<int> p;
	cout << s.maxProfit(p) << endl;
}
