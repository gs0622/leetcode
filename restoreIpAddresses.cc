#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// enumerate all combinations, carefully deal w/ invalid ones, total length, and leading 0
	vector<string> restoreIpAddresses(string s) {
		vector<string> ans;
		int i,j,k,m;
		for (i=1;i<4;++i)
		for (j=1;j<4;++j)
		for (k=1;k<4;++k)
		for (m=1;m<4;++m) {
			// enumerate all possible valid ones
			if (i+j+k+m != s.size()) continue;
			int a, b, c, d;
			// use stoi to strip leading 0 of substr
			a = stoi(s.substr(0,i));
			b = stoi(s.substr(i,j));
			c = stoi(s.substr(i+j,k));
			d = stoi(s.substr(i+j+k, m));
			if (a>255 || b>255 || c>255 || d>255) continue;
			if (to_string(a).size()+to_string(b).size()+to_string(c).size()+to_string(d).size()!=s.size()) continue;
			string ip = to_string(a) + '.' + to_string(b) + '.'+ to_string(c) + '.' + to_string(d);
			//cout << ip << endl;
			ans.push_back(ip);
		}
		return ans;
	}
};
int main(){
	Solution s;
	vector<string> ans;
	string s0{"25525511135"};
	ans = s.restoreIpAddresses(s0);
	for (auto ip: ans) cout << ip << endl;
	cout << "---" << endl;
	string s1{""};
	ans = s.restoreIpAddresses(s1);
	for (auto ip: ans) cout << ip << endl;
	string s2{"010010"};
	ans = s.restoreIpAddresses(s2);
	for (auto ip: ans) cout << ip << endl;
}
