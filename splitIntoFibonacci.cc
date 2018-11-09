#include <bits/stdc++.h>
using namespace std;
class Solution {
	string add(string a, string b) {
		int i=a.size()-1, j=b.size()-1, carry=0;
		string res;
		while (i>=0 || j>=0) {	// backward adding
			int sum=(i>=0?a[i--]-'0':0) + (j>=0?b[j--]-'0':0) + carry;
			res = to_string(sum%10) + res;
			carry = sum/10;
		}
		if (carry) res = "1"+res;
		return res;
	}
public:
	vector<int> splitIntoFibonacci(string S) {
		int n=S.size();
		vector<int> res;
		function<bool(string,string,string)> helper=[&](string s1, string s2, string s3){
			if (s1.size()>1 && s1[0]=='0') return false;
			if (s2.size()>1 && s2[0]=='0') return false;
			string sum=add(s1,s2);
			long long v3 = stoll(sum);
			if (v3>INT_MAX) return false;
			res.push_back((int)v3);
			if (sum==s3)
				return true;
			if (sum.size()>s3.size() || s3.compare(0,sum.size(),sum)!=0) {
				res.pop_back();
				return false;
			}
			bool ans=helper(s2,sum,s3.substr(sum.size())); // evaluate new cut of f1/f2/f3;
			if (!ans) res.pop_back();
			return ans;
		};
		for (int i=1; i<n && i<11; ++i) {
			string f1=S.substr(0,i);
			long long v1 = stoll(f1);
			if (v1>INT_MAX) continue;
			res.push_back((int)v1);
			for (int j=1; i+j<n && j<11; ++j) {
				string f2=S.substr(i,j), rest=S.substr(i+j);
				long long v2 = stoll(f2);
				if (v2>INT_MAX) continue;
				res.push_back(stoi(f2));
				if (helper(f1,f2,rest)==true)
					return res;
				res.pop_back();
			}
			res.pop_back();
		}
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
