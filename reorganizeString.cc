/* https://leetcode.com/problems/reorganize-string/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string reorganizeString2(string S) {		// priority_queue associates w/ hash map
		unordered_map<char,int> cnt;
		for (auto c: S) ++cnt[c];
		priority_queue<pair<int,char>> pq;	// maxheap
		for (auto p: cnt) pq.push(make_pair(p.second, p.first));
		for (int i=0; i<S.size(); ++i) {		// same as previous solution while take two per iteration
			if (pq.empty()) return "";		// not possible in terms of freq
			auto p=pq.top(); pq.pop();
			S[i]=p.second;
			if (i+1<S.size()) {
				if (pq.empty()) return "";	// not possible in terms of freq
				auto q=pq.top(); pq.pop();
				S[i+1]=q.second, ++i;
				if (--q.first > 0) pq.push(q);
			}
			if (--p.first > 0) pq.push(p);
		}
		return S;
	}
	string reorganizeString1(string S) {	// priority_queue associates w/ hash map
		unordered_map<char,int> cnt;
		for (auto c: S) ++cnt[c];

		function<bool(char,char)> cmp = [&](char a, char b){return cnt[a]<cnt[b];}; // less
		priority_queue<char, vector<char>, decltype(cmp)> pq(cmp);
		for (auto p: cnt)
			pq.push(p.first);
		for (int i=0, prev=-1; i<S.size(); ++i) {
			if (pq.empty() && prev>=0) return "";
			S[i] = pq.top(), pq.pop();
			if (prev != -1) pq.push(prev);	// S[i] remains
			prev = --cnt[S[i]]>0? S[i]: -1;
		}
		return S;
	}
	string reorganizeString(string S) {
		vector<int> cnt(26,0);			// vector map rather than hashmap
		for (auto c: S) cnt[c-'a']++;

		auto cmp = [&cnt](int i, int j) {
			return cnt[i] < cnt[j];
		};
		priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
		for (int i=0; i<26; ++i)
			if (cnt[i] > 0) pq.push(i);

		for (int i=0, prev=-1; i<S.size(); ++i) {
			if (pq.empty() && prev>=0) return "";
			int j=pq.top();
			pq.pop();
			S[i]=j+'a';
			if (prev>=0) pq.push(prev);
			prev=--cnt[j]<=0? -1: j;
		}
		return S;
	}
};
int main(){
	Solution s;
	//string str1{"aab"}, cp1(str1), cp2(str1);
	string str1{"vvvlo"}, cp1(str1), cp2(str1);
	cout << s.reorganizeString1(cp1) << ": " << s.reorganizeString2(cp2) << endl;
	string str2{"aaab"}, cp21(str2), cp22(str2);
	cout << s.reorganizeString1(cp21) << ": " << s.reorganizeString2(cp22) << endl;
}
