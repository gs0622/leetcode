/* https://leetcode.com/problems/word-ladder/description/
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int ladderLength2(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> head, tail, *phead, *ptail, wordSet(begin(wordList), end(wordList));
		head.insert(beginWord), tail.insert(endWord);
		int dist=2; // first + last step
		while (!head.empty() && !tail.empty()) {
			if (head.size()<tail.size()) phead=&head, ptail=&tail;
			else phead=&tail, ptail=&head;
			unordered_set<string> tmp;
			for (auto it=phead->begin(); it!=phead->end(); ++it) {
				string s=*it;
				wordSet.erase(s);	// like queue pop
				for (int i=0; i<s.size(); ++i) {
					int ch=s[i];
					for (int j=0; j<26; ++j) {
						s[i]='a'+j;
						if (ptail->count(s))	
							return dist;
						if (wordSet.count(s))
							tmp.insert(s), wordSet.erase(s);
					}
					s[i]=ch;
				}
			}
			++dist;
			swap(*phead, tmp);
		}
		return 0;
	}
	// BFS
	int ladderLength1(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> wordSet(begin(wordList), end(wordList));
		if (wordSet.count(endWord)==0) return 0;
		queue<string> q;
		function<void(string)> next=[&](string s){
			wordSet.erase(s);			// visit
			for (int i=0; i<s.size(); ++i) {	// enumarate all position
				int ch = s[i];
				for (int j=0; j<26; ++j) {	// enumerate all char except same one
					int tmp = 'a'+j;
					if (tmp==ch) continue;
					s[i]=tmp;
					if (wordSet.count(s))	// in case one edit dist, push into queue
						q.push(s);
				}
				s[i]=ch;
			}
		};
		next(beginWord);
		int dist=1;
		while (!q.empty()) {
			int n=q.size();
			for (int i=0; i<n; ++i) {
				string s = q.front(); q.pop();
				if (s==endWord) return dist+1; // the last move, or assign dist=2 initially
				next(s);
			}
			++dist;
		}
		return 0;
	}
	// buggy; sort first
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		function<int(string,string)> dist=[](string a, string b) {
			int cnt=0;
			for (int i=0,j=0; i<a.size() && j<b.size(); ++i, ++j)
				if (a[i]!=b[j]) ++cnt;
			return cnt;
		};
		function<bool(string,string)> helper=[&](string a, string b) {
			return dist(beginWord,a) < dist(beginWord,b);
		};
		sort(begin(wordList), end(wordList), helper);
		string s = beginWord;
		int cnt=0;
		for (int i=0; i<wordList.size(); ++i) {
			if (s == endWord) return cnt;
			if (dist(s, wordList[i])==1)
				cnt++, s=wordList[i];
		}
		return s==endWord? cnt: 0;
	}
};
int main(){
	Solution s;
	string b1{"hit"}, e1{"cog"};
	vector<string> w1{"hot","dot","dog","lot","log","cog"};
	vector<string> w2{"hot","dot","dog","lot","log"};
	string b3{"hot"}, e3{"dog"};
	vector<string> w3{"hot","dog","dot"};
	string b4{"a"}, e4{"c"};
	vector<string> w4{"a","b","c"};
	cout << s.ladderLength2(b1, e1, w1) << endl;
	cout << s.ladderLength2(b1, e1, w2) << endl;
	cout << s.ladderLength2(b3, e3, w3) << endl;
	cout << s.ladderLength2(b4, e4, w4) << endl;
}
