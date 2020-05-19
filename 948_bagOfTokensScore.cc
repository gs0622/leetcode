#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// Greedy two-pointer: buy the cheapest sell the expensive
	int bagOfTokensScore(vector<int>& tokens, int P) {
		sort(tokens.begin(), tokens.end());
		int res=0, pts=0, i=0, j=tokens.size()-1;
		while (i<=j) {
			if (P>=tokens[i])
				P-=tokens[i++], res = max(res, ++pts);
			else if (pts>0)
				P+=tokens[j--], --pts;
			else
				break;
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<int> A1{100,200,300,400};
	cout << s.bagOfTokensScore(A1, 200) << endl;
}
