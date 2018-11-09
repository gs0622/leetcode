#include <bits/stdc++.h>
using namespace std;
class Solution {
	// wrong because it implies sequence
	bool helper(string a, string b) {
		int m=a.size(), n=b.size(), i, j=0;
		for (i=0, j=0; i<m && j<n ; ++i) {
			if (b[j]==a[i]) ++j;
		}
		return j==n;
	}
	bool helper1(string a, string b) {
		unordered_map<char,int> ma, mb;
		for (auto c: a) ++ma[c];
		for (auto c: b) ++mb[c];
		for (auto it: mb) {
			if (ma[it.first]<it.second)
				return false;
		}
		return true;
	}
public:
	vector<string> wordSubsets1(vector<string>& A, vector<string>& B) {
		unordered_map<char,int> uni;
		for (auto b: B) {
			unordered_map<char,int> mb;
			for (auto c: b) {
				++mb[c];
				uni[c]=max(uni[c],mb[c]);
			}
		}
		vector<string> res;
		for (auto a: A) {
			unordered_map<char,int> ma;
			for (auto c: a)
				++ma[c];
			res.push_back(a);
			for (auto it=uni.begin(); it!=uni.end(); ++it) {
				//cout << it->first << ": " << ma[it->first] << " vs. " << it->second << endl;
				if (ma[it->first] < it->second) {
					res.pop_back();
					break;
				}
			}
		}
		return res;		
	}
	vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
		vector<string> res;
		int i, n=B.size();
		for (auto a: A) {
			i=0;
			for (auto b: B) {
				if (helper1(a,b))
					++i;
			}
			if (i==n)
				res.push_back(a);
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<string> res;
	vector<string> A1{"amazon","apple","facebook","google","leetcode"}, B1{"e", "o"};
	res = s.wordSubsets1(A1,B1);
	for (auto s: res) cout << s << " ";
	cout << endl;
	vector<string> A2=A1, B2{"l","e"};
	res = s.wordSubsets1(A2,B2);
	for (auto s: res) cout << s << " ";
	cout << endl;
	vector<string> A3=A1, B3{"e","oo"};
	res = s.wordSubsets1(A3,B3);
	for (auto s: res) cout << s << " ";
	cout << endl;
	vector<string> A4=A1, B4{"lo","eo"};
	res = s.wordSubsets1(A4,B4);
	for (auto s: res) cout << s << " ";
	cout << endl;
	vector<string> A5=A1, B5{"ec","oc","ceo"};
	res = s.wordSubsets1(A5,B5);
	for (auto s: res) cout << s << " ";
	cout << endl;
}
