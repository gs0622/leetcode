#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// same as orignal one, while much cleaner
	// reference: https://leetcode.com/problems/positions-of-large-groups/discuss/128957/C++JavaPython-Straight-Forward
	vector<vector<int>> largeGroupPositions1(string S) {
		vector<vector<int>> res;
		int i=0,j=0,n=S.size();
		while (j<n) {
			while (j<n && S[i]==S[j]) ++j;
			if (j-i>=3) res.push_back({i,j-1});
			i=j;
		}
		return res;
	}
	// my brute-force, need care of boundry condition, read new one and review why it is cleaner?
	vector<vector<int>> largeGroupPositions(string S) {
		vector<vector<int>> res;
		int i,j,cnt;
		for (i=0,j=1,cnt=1; j<S.size(); ++j) {
			if (S[i]==S[j]) ++cnt;
			else {
				if (cnt>=3) res.push_back({i,j-1});
				i=j,cnt=1;
			}
		}
		if (cnt>=3) res.push_back({i,j-1});
		return res;
	}
};
int main(){
	Solution s;
	string s1{"abbxxxxzzy"};
	string s2{"abc"};
	string s3{"abcdddeeeeaabbbcd"};
	string s4{"aaa"};
	vector<vector<int>> res;
	res=s.largeGroupPositions1(s1);
	for (auto p: res) cout << p[0] << ',' << p[1] << ' ';
	cout << endl;
	res=s.largeGroupPositions1(s2);
	for (auto p: res) cout << p[0] << ',' << p[1] << ' ';
	cout << endl;
	res=s.largeGroupPositions1(s3);
	for (auto p: res) cout << p[0] << ',' << p[1] << ' ';
	cout << endl;
	res=s.largeGroupPositions1(s4);
	for (auto p: res) cout << p[0] << ',' << p[1] << ' ';
	cout << endl;
}
