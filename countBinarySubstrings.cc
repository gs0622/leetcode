#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	int countBinarySubstrings(string s) {
		int ans=0, base=0, slow=0, n=s.size();
		while (base<n) {
			int fast=0;
			while (s[base]==s[base+fast]) fast+=1; // until 1/0 flip
			ans += min(slow,fast);
			base+=fast;
			slow=fast;
		}
		return ans;
	}
	int countBinarySubstrings2(string s) {
		int ans=0, prev=0, cur=1;
		for (int i=1; i<s.size(); ++i) {
			cout << s.substr(0, i+1) << endl;
			if (s[i]==s[i-1]) cur+=1;
			else prev=cur, cur=1;
			if (prev>=cur) ans+=1;
		}
		return ans;
	}
	vector<string> substrs(string s) {
		vector<string> ss;
		for (int i=0; i<s.size(); ++i) {
			for (int j=2; j<=s.size()-i; j+=2) ss.push_back(s.substr(i, j));
		}
		return ss;
	}
};
int main(){
	Solution s;
	//vector<string> ss = s.substrs("000111");
	//vector<string> ss = s.substrs("11100");
	//for (auto sss: ss) cout << sss << endl;
	cout << s.countBinarySubstrings("00110011") << endl;
	//cout << s.countBinarySubstrings("00110") << endl;
}
