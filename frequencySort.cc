/* https://leetcode.com/problems/sort-characters-by-frequency/description/
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char,int> m;	// freq table
		for (auto c: s) m[c]++;		// O(n)

		auto cmp = [&m](char a, char b) {
			// freq take prioirty, follow by alpha-beta
			return m[a] > m[b] || (m[a]==m[b] && a>b);
		};

		sort(s.begin(), s.end(), cmp);	// O(nlog(n)): use freq table plus cmp to sort
		return s;
	}
	// O(n) space
	string frequencySort2(string s) {
		unordered_map<char,int> m;
		for (auto c: s) m[c]++;			// cnt, val
		priority_queue<pair<int,char>> pq;	// maxheap
		for (auto n: m)				// high freq in the pq.top, nlogn
			pq.push(make_pair(n.second, n.first));
		string r;
		while (!pq.empty()) {			// dump to string
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

