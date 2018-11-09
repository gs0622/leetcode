/* https://leetcode.com/problems/partition-labels/description/

A string S of lowercase letters is given.
We want to partition this string into as many parts as possible
so that each letter appears in at most one part,
and return a list of integers representing the size of these parts.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> partitionLabels(string S) {
		vector<int> res, pos(26, 0);  
		for (auto i = 0; i < S.size(); ++i) pos[S[i] - 'a'] = i;
		for (auto i = 0, idx = INT_MIN, last = 0; i < S.size(); ++i) {
			idx = max(idx, pos[S[i] - 'a']);
			if (idx == i) res.push_back(i - last + 1), last = i+1;
		}
		return res;
	}
	vector<int> partitionLabels1(string S) {
		unordered_map<char,int> map;
		for (int i=0; i<S.size(); ++i)
			map[S[i]]=i;
		vector<int> res;
		for (int i=0, s=0, e=0; i<S.size(); ++i) {
			e = max(e, map[S[i]]);	// greedy: keep max of each char
			if (e==i)		// exceed, make partition
				res.push_back(e-s+1), s=e+1;
		}
		return res;
	}
};
int main(){
	Solution s;
	//string s1{"ababcbacadefegdehijhklij"};
	string s1{"abcde"};
	for (auto n: s.partitionLabels1(s1)) cout << n << ' ';
	cout << endl;
}
