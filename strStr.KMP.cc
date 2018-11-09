/* reference: https://hk.saowen.com/a/f87c5d20b526923e705d85fcef237c2d0a3fd1b7a6c81fc02a67d3dfd8aebe82
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> getNext(string p) {
		vector<int> res(p.size(), -1);
		int k=-1, i=0;
		while (i<p.size()-1)
			if (k==-1 || p[i]==p[k]) res[++i] = ++k;
			else k=res[k];
		return res;
	}
	void getNext(vector<int>& next, string p) {
		next[0] = -1;
		int k = -1, i = 0;
		while (i < p.size() - 1) {
			if (k == -1 || p[i] == p[k]) next[++i] = ++k;
			else k = next[k];
		}
	}
	int strStr(string s, string p) {
		if (p.empty()) return 0;
		vector<int> next(p.size(), 0);
		getNext(next, p);		// preprocessing: O(n)
		int i = 0, j = 0;
		while (i < s.size() && j < p.size()) {
			if (s[i] == p[j]) i++, j++;
			else {
				if(j == 0) i++;
				else j = next[j];
			}
		}
		return j == p.size() ? i - j : -1;
	}
};

int main(void) {
	//string a("missisippi");
	//string b("issi");
	//string a("12345");
	//string b("345");
	string a("aaaaaaaaaaaaaaaaaaaaaaaaaab");
	string b("aaaaaaaab");
	Solution s;
	cout << s.strStr(a, b) << endl;
	string s1{"ababab"};
	vector<int> next;
	next=s.getNext(s1);
	for (auto n: next) cout << n << ' ';
	cout << endl;
}
