#include <bits/stdc++.h>
using namespace std;
class Solution {
	struct TrieNode {
		vector<TrieNode*> nodes;
		bool isWord;
		TrieNode (): isWord(false) {nodes.resize(26,nullptr);}
	};
	TrieNode root;
	string findRoot(string s) {
		TrieNode* p = &root;
		string r;
		for (int i=0; i<s.size() && p; ++i) {
			if (p->isWord) break;
			p=p->nodes[s[i]-'a'];
			r+=s[i];
		}
		return p? r: s;
	}
	void insert(string s) {
		TrieNode *p = &root;
		for (int i=0; i<s.size(); ++i) {
			if (p->nodes[s[i]-'a']==nullptr)
				p->nodes[s[i]-'a']=new TrieNode();
			p=p->nodes[s[i]-'a'];
		}
		p->isWord=true;
	}
public:
	string replaceWords2(vector<string>& dict, string sentence) {
		unordered_set<string> dset(dict.begin(), dict.end());
		istringstream iss(sentence);
		string res, w;
		while (iss>>w) {
			string prefix;
			for (int i=1; i<=w.size(); ++i) {
				prefix=w.substr(0,i);
				if (dset.count(prefix)) break;
			}
			res+=prefix;	// original string or shortest root
			if (iss.good()) res+=' ';
			
		}
		return res;
	}
	string replaceWords1(vector<string>& dict, string sentence) {
		for (auto d: dict) insert(d);
		istringstream iss(sentence);
		string s, w;
		while (iss>>w) {
			string r=findRoot(w);
			if (!r.empty()) w=r;
			s+=r;
			if (iss.good()) s+=' ';

		}
		return s;
	}
	// O(mn) m=words of sent, n=dict size
	string replaceWords(vector<string>& dict, string sentence) {
		istringstream iss(sentence);
		string s, w;
		while (iss>>w) {
			for (string d: dict) {
				if (w.compare(0,d.size(),d)==0)	// long root will be replaced by shorter one
					w=d;
			}
			s+=w;
			if (iss.good()) s+=' ';

		}
		return s;
	}
};
int main(){
	Solution s;
	vector<string> dict{"cat", "bat", "rat","catt"};
	string sent{"the cattle was rattled by the battery"};
	cout << s.replaceWords2(dict, sent) << endl;
}
