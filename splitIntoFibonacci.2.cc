#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> splitIntoFibonacci(string S) {
		int n=S.size();
		vector<int> res, ans;
		function<bool(int)> valid=[&](int v) {
			int m=ans.size();
			return m<2 || ans[m-2]+ans[m-1]==v;
		};
		function<void(int)> helper=[&](int st){
			if (st==S.size() && ans.size()>=3) {		// backtrack-1: terminal cond
				res=ans;				// copy current ans to res, else backtracking will pop ans.back
				return;
			}
			//for (int i=st; i<n; ++i) {			// backtrack-2: enumarate all cases
			for (int i=st; i<n && res.empty(); ++i) {	// backtrack-2: enumarate all cases
				string s=S.substr(st,i-st+1);
				if (s.size()>1 && s[0]=='0') return;	// check: invalid leading zero
				long long v=stoll(s);
				if (v>INT_MAX) return;			// check: overflow
				if (valid(v)) {				// backtrack-3: careful dfs, push and pop candidate
					ans.push_back(v);
					helper(i+1);
					ans.pop_back();
				}
			}
		};
		helper(0);
		return res;
	}
};
int main(){
	Solution s;
	vector<int> res;
	string s0{"214748364721474836422147483641"};
	string s1{"123456579"};
	string s2{"11235813"};
	string s3{"112358130"};
	string s4{"0123"};
	//string s5{"1101111"};
	string s5{"1011"};
	res=s.splitIntoFibonacci(s5);
	for (auto n: res) cout << n << ' ';
	cout << endl;
	res=s.splitIntoFibonacci(s2);
	for (auto n: res) cout << n << ' ';
	cout << endl;
	res=s.splitIntoFibonacci(s3);
	for (auto n: res) cout << n << ' ';
	cout << endl;
	res=s.splitIntoFibonacci(s4);
	for (auto n: res) cout << n << ' ';
	cout << endl;
	res=s.splitIntoFibonacci(s5);
	for (auto n: res) cout << n << ' ';
	cout << endl;
}
