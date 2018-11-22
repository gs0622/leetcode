#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class Solution {
public:
	// O(n) greedy
	vi diStringMatch(string S) {
		int L=0, R=S.size(), n=S.size();
		vi res;
		for (int i=0; i<=n; ++i) {	// 0 to n (n+1), both sides start, eventually meet
			if (S[i] == 'I') res.push_back(L++);
			else res.push_back(R--);
		}
		return res;
	}
};
int main(){
	Solution s;
	vi res;
	res = s.diStringMatch("IDID");
	for (auto n: res) cout << n << ' ';
	cout << endl;
	res = s.diStringMatch("III");
	for (auto n: res) cout << n << ' ';
	cout << endl;
	res = s.diStringMatch("DDI");
	for (auto n: res) cout << n << ' ';
	cout << endl;
}
