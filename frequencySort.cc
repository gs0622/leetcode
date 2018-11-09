/* https://leetcode.com/problems/sort-characters-by-frequency/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char,int> m;	// freq table
		for (auto c: s) m[c]++;

		auto cmp = [&m](char a, char b) {
			// freq take prioirty, follow by alpha-beta
			return m[a] > m[b] || (m[a]==m[b] && a>b);
		};

		sort(s.begin(), s.end(), cmp);
		return s;
	}
	// O(n) space
	string frequencySort2(string s) {
		unordered_map<char,int> m;
		for (auto c: s) m[c]++;
		priority_queue<pair<int,char>> pq;
		for (auto n: m) pq.push(make_pair(n.second, n.first));
		string r;
		while (!pq.empty()) {
			auto q = pq.top();
			int i = q.first;
			while (i--) r += q.second;
			pq.pop();
		}
		return r;
	}
};
int main(){
	Solution s;
	string s1{"tree"};
	cout << s.frequencySort(s1) << endl;
	string s2{"cccaaa"};
	cout << s.frequencySort(s2) << endl;
	string s3{"Aabb"};
	cout << s.frequencySort(s3) << endl;
	string s4{"loveleetcode"};
	cout << s.frequencySort(s4) << endl;
	string s5{"2a554442f544asfasssffffasss"};
	cout << s.frequencySort(s5) << endl;
	string s6{"dacca"};
	cout << s.frequencySort(s6) << endl;
}

