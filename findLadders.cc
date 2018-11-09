/* https://leetcode.com/problems/word-ladder-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
	vector<vector<string>> findLadders(string B, string E, vector<string>& W) {
		unordered_set<string> dict(W.begin(),W.end());
		if (!dict.count(E)) return {};
		vector<vector<string>> paths;
		vector<string> path(1, B);
		if (B == E) {
			paths.push_back(path);
			return paths;
		}
		unordered_set<string> words1, words2;
		words1.insert(B);
		words2.insert(E);
		unordered_map<string, vector<string>> nexts;
		bool words1IsBegin = false;
		if (findLaddersHelper(words1, words2, dict, nexts, words1IsBegin))
			getPath(B, E, nexts, path, paths);
		return paths;
	}
private:
	bool findLaddersHelper(
		unordered_set<string> &words1,
		unordered_set<string> &words2,
		unordered_set<string> &dict,
		unordered_map<string, vector<string> > &nexts,
		bool &words1IsBegin) {
		words1IsBegin = !words1IsBegin;
		if (words1.empty()) return false;
		if (words1.size() > words2.size())
			return findLaddersHelper(words2, words1, dict, nexts, words1IsBegin);
		for (auto it = words1.begin(); it != words1.end(); ++it)
			dict.erase(*it);
		for (auto it = words2.begin(); it != words2.end(); ++it)
			dict.erase(*it);
		unordered_set<string> words3;
		bool reach = false;
		for (auto it = words1.begin(); it != words1.end(); ++it) {
			std::string word = *it;
			for (auto ch = word.begin(); ch != word.end(); ++ch) {
				char tmp = *ch;
				for (*ch = 'a'; *ch <= 'z'; ++(*ch))
					if (*ch != tmp)
						if (words2.find(word) != words2.end()) {
							reach = true;
							words1IsBegin ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
						}
						else if (!reach && dict.find(word) != dict.end()) {
							words3.insert(word);
							words1IsBegin ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
						}
				*ch = tmp;
			}
		}
		return reach || findLaddersHelper(words2, words3, dict, nexts, words1IsBegin);
	}
	void getPath(
		string &B,
		string &E,
		unordered_map<string, vector<string> > &nexts,
		vector<string> &path,
		vector<vector<string> > &paths) {
		if (B == E)
			paths.push_back(path);
		else
			for (auto it = nexts[B].begin(); it != nexts[B].end(); ++it) {
				path.push_back(*it);
				getPath(*it, E, nexts, path, paths);
				path.pop_back();
			}
	}
};
class Solution {
public:
	// BFS+DFS, TLE, 21 / 39 test cases passed.
	vector<vector<string>> findLadders1(string B, string E, vector<string>& W) {
		unordered_set<string> ws1(W.begin(), W.end()), ws2(W.begin(), W.end()), head, tail, *phead, *ptail;
		if (!ws1.count(E)) return {};
		head.insert(B), tail.insert(E);
		int dist=1;
		int done=0;
		unordered_map<string, vector<string>> nexts;
		while (!head.empty() && !tail.empty()) {
			if (head.size()<tail.size()) phead=&head, ptail=&tail;
			else phead=&tail,ptail=&head;
			unordered_set<string> tmp;
			for (auto it=phead->begin(); it!=phead->end(); ++it) {		// level
				string s=*it;
				ws1.erase(s);
				for (int i=0; i<s.size(); ++i) {
					int ch=s[i];
					for (int j=0; j<26; ++j) {
						s[i]='a'+j;
						if (ptail->count(s)) {
							phead==&head? nexts[*it].push_back(s): nexts[s].push_back(*it);
							done=1;
							break;
						}
						if (ws1.count(s)) {
							tmp.insert(s);
							phead==&head? nexts[*it].push_back(s): nexts[s].push_back(*it);
						}
					}
					s[i]=ch;
				}
			}
			++dist;
			swap(*phead,tmp);
			if (done) break;
		}
		vector<vector<string>> res;
		vector<string> ans(1, B);
		function<void(string)> dfs=[&](string s) {
			if (ans.size()>dist) return;
			if (s==E) {
				res.push_back(ans);
				return;
			}
			for (auto it=nexts[s].begin(); it!=nexts[s].end(); ++it) {
					ans.push_back(*it);
					dfs(*it);		// recursive
					ans.pop_back();		// backtracing
			}
		};
		dfs(B);
		return res;
	}
	// DFS, TLE, 19 / 39 test cases passed.
	vector<vector<string>> findLadders(string B, string E, vector<string>& W) {
		unordered_set<string> ws(W.begin(), W.end());
		vector<vector<string>> res;
		vector<string> ans(1, B);
		function<void(string)> dfs=[&](string s){
			if (s==E) { res.push_back(ans); return; }
			ws.erase(s);				// visit
			for (int i=0; i<s.size(); ++i) {
				int ch=s[i];
				for (int j=0; j<26; ++j) {
					s[i]='a'+j;
					ans.push_back(s);
					if (ws.count(s)) dfs(s);
					ans.pop_back();
				}
				s[i]=ch;
			}
			ws.insert(s);
		};
		dfs(B);
		int shortest=INT_MAX;
		for (auto r: res) shortest=min(shortest, (int)r.size());
		vector<vector<string>> res2;
		for (auto r: res) if (r.size()==shortest) res2.push_back(r);
		return res2;
	}
};
int main(){
	Solution s;
	vector<string> W1{"hot","dot","dog","lot","log","cog"};
	vector<string> W2{"hot","dog","dot"};
	vector<string> W3{"hot","dot","dog","lot","log"};
	vector<string> W4{"hot","dog"};
	vector<vector<string>> res;
	res=s.findLadders1("hit","cog", W1);
	for (auto r: res) { for (auto s: r) cout << s << ' '; cout << endl; }
	res=s.findLadders1("hot","dog", W2);
	for (auto r: res) { for (auto s: r) cout << s << ' '; cout << endl; }
	res=s.findLadders1("hit","cog", W3);
	for (auto r: res) { for (auto s: r) cout << s << ' '; cout << endl; }
	res=s.findLadders1("hot","dog", W4);
	for (auto r: res) { for (auto s: r) cout << s << ' '; cout << endl; }
}
