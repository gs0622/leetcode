#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> shortestToChar(string S, char C) {
		int n=S.size();
		vector<int> res(n,n);
		for (int i=0; i<n; ++i) if (S[i]==C) res[i]=0;			// mark 0
		for (int i=1; i<n; ++i) res[i]=min(res[i], res[i-1]+1);		// go right
		for (int i=n-2; i>=0; --i) res[i]=min(res[i], res[i+1]+1);	// go left
		return res;
	}
};
int main(){
	Solution s;
	for (auto n: s.shortestToChar("loveleetcode", 'e')) cout << n << " ";
	cout << endl;
}
