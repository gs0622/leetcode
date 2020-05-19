#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		if (s.size()<=10) return vector<string>();
		unordered_map<string, int> m;
		vector<string> ans;
		for (int i=0; i<=s.size()-10; ++i) {
			string ss = s.substr(i,10);
			if (m[ss]==1) ans.push_back(ss); // only once
			m[ss] += 1;
		}
		return ans;
	}
	vector<string> findRepeatedDnaSequences2(string s) {
		if (s.size()<11) return vector<string>();
		unordered_map<string, int> m;
		vector<string> ans;
		for (int i=0; i<=s.size()-10; ++i) {
			m[s.substr(i,10)] += 1;
		}
		for (auto it: m) {
			if (it.second > 1) ans.push_back(it.first);
		}
		return ans;
	}
};
int main(){
	Solution s;
	string d1{"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"};
	string d2{"AAAAAAAAAAA"};
	string d3{""};
	vector<string> v1 = s.findRepeatedDnaSequences(d1);
	for (auto t: v1) cout << t << " ";
	cout << endl;
	vector<string> v2 = s.findRepeatedDnaSequences(d2);
	for (auto t: v2) cout << t << " ";
	cout << endl;
	vector<string> v3 = s.findRepeatedDnaSequences(d3);
	for (auto t: v3) cout << t << " ";
	cout << endl;
}
