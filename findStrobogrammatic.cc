#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<string> findStrobogrammatic1(int n) {
		vector<vector<string>> init{{""},{"0","1","8"},{""}};
		vector<string> res=init[n%2];
		for (int i=n%2+2; i<=n; i+=2){
			vector<string> tmp ;
			for (auto s: res) {
				if (i!=n) tmp.push_back("0"+s+"0");
				tmp.push_back("1"+s+"1");
				tmp.push_back("6"+s+"9");
				tmp.push_back("8"+s+"8");
				tmp.push_back("9"+s+"6");
			}
			res.swap(tmp);
		}
		return res;
	}
	vector<string> findStrobogrammatic(int n) {
		vector<string> res;
		function<vector<string>(int)> dfs=[&](int m) {
			if (m==0) return vector<string>{""};
			if (m==1) return vector<string>{"0","1","8"};
			vector<string> t = dfs(m-2), r;
			for (auto s: t) {
				if (m!=n) r.push_back("0"+s+"0");
				r.push_back("1"+s+"1");
				r.push_back("6"+s+"9");
				r.push_back("8"+s+"8");
				r.push_back("9"+s+"6");
			}
			return r;
		};
		res = dfs(n);
		return res;
	}
};
int main(){
	Solution s;
	vector<string> res;
	res = s.findStrobogrammatic1(1);
	for (auto ss: res) cout << ss << ' ';
	cout << endl;
	res = s.findStrobogrammatic1(2);
	for (auto ss: res) cout << ss << ' ';
	cout << endl;
	res = s.findStrobogrammatic1(3);
	for (auto ss: res) cout << ss << ' ';
	cout << endl;
	res = s.findStrobogrammatic1(4);
	for (auto ss: res) cout << ss << ' ';
	cout << endl;
};
