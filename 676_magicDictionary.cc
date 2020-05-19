#include <bits/stdc++.h>
using namespace std;
class MagicDictionary {
	unordered_map<string,unordered_set<string>> mp;
public:
	/** Initialize your data structure here. */
	MagicDictionary() {
		mp.clear();
		
	}
	/** Build a dictionary through a list of words */
	void buildDict(vector<string> dict) {
		for (auto w: dict) {
			int n=w.size();
			for (int i=0; i<n; ++i) {
				for (int j=0; j<26; ++j) {
					string ww = w;
					if (w[i]!='a'+j) {
						ww[i]='a'+j;
						mp[w].insert(ww);
					}
				}
			}
		}
	}
	/** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
	bool search(string word) {
		for (auto it: mp) {
			if (it.first.size() == word.size())
				if (it.second.count(word)) return true;
		}
		return false;
	}
};
int main(){
	MagicDictionary obj;
	vector<string> dict{"hello", "leetcode"};
	obj.buildDict(dict);
	cout << obj.search("hello") << endl;
	cout << obj.search("hhllo") << endl;
	cout << obj.search("hell") << endl;
	cout << obj.search("leetcoded") << endl;
}
