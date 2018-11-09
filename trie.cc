/* https://leetcode.com/problems/implement-trie-prefix-tree/description/
Implement a trie with insert, search, and startsWith methods.
Note:
You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/
#include <bits/stdc++.h>
using namespace std;
class Trie {
	struct TrieNode {
		vector<TrieNode*> nodes;
		bool isEOW;			// is end of word;
		TrieNode(): isEOW(false) { nodes.resize(26,nullptr); }
		
	};
	TrieNode root;
	TrieNode* find(string s) {
		TrieNode* p = &root;
		for (int i=0; i<s.size() && p!=nullptr; ++i)
			p = p->nodes[s[i]-'a'];
		return p;
	}
public:
	void insert(string word) {
		TrieNode *p = &root;
		for (int i=0; i<word.size(); ++i) {
			if (p->nodes[word[i]-'a']==nullptr)
				p->nodes[word[i]-'a']=new TrieNode();
			p=p->nodes[word[i]-'a'];
		}
		p->isEOW=true;
	}
	bool search(string word) {
		TrieNode *p = find(word);
		return p && p->isEOW; 
	}
	bool startsWith(string prefix) {
		return find(prefix)!=nullptr;
	}
	vector<string> autocomplete(string prefix) {
		if (!startsWith(prefix)) return {};
		vector<string> res;
		queue<pair<TrieNode*,string>> q;
		q.push(make_pair(find(prefix),prefix));
		while (!q.empty()) {
			TrieNode* cur=q.front().first;
			string s=q.front().second;
			q.pop();
			if (cur->isEOW) res.push_back(s);
			for (int i=0; i<26; ++i) {
				string ss=s+char('a'+i);
				TrieNode *p=find(ss);
				if (p) q.push(make_pair(p,ss));
			}
		}
		return res;
	}
};
int main(){
	Trie trie;

	trie.insert("apple");
	cout << trie.search("apple") << endl;	// returns true
	cout << trie.search("app") << endl;	// returns false
	cout << trie.startsWith("app") << endl;	// returns true

	trie.insert("app");
	trie.insert("application");
	trie.insert("apb");
	cout << trie.search("app") << endl;	// returns true

	vector<string> res;
	res=trie.autocomplete("ap");
	for (auto s: res) cout << s << endl;
}
