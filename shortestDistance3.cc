/*
This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

Note:
You may assume word1 and word2 are both in the list.
*/
#include <bits/stdc++.h>
using namespace std;
class WordDistance {
	unordered_map<string,vector<int>> mp;	// conside dup keys, values in vector
public:
	WordDistance(vector<string>& words) {
		for (int i=0; i<words.size(); ++i) mp[words[i]].push_back(i);
	}
	int shortest2(vector<string> words, string word1, string word2) {
		int p1=-1, p2=-1, res=INT_MAX;
		for (int i=0; i<words.size(); ++i) {
			int last=p1;
			if (words[i]==word1) p1=i;
			if (words[i]==word2) p2=i;
			if (p1!=-1 && p2!=-1) {
				if (p1!=p2) res=min(res,abs(p1-p2));
				else if (last!=-1 && last!=p1) res=min(res,abs(last-p1));
			}
		}
		return res;
	}
	int shortest1(vector<string> words, string word1, string word2) {
		int p1=words.size(), p2=-p1, res=INT_MAX;
		for (int i=0; i<words.size(); ++i) {
			if (words[i]==word1) p1=(word1==word2)? p2: i;
			if (words[i]==word2) p2=i;
			res=min(res,abs(p1-p2));
		}
		return res;
	}
	// O(mn)
	int shortest(string word1, string word2) {
		int res=INT_MAX;
		for (int i=0;i<mp[word1].size();++i) for (int j=0; j<mp[word2].size(); ++j) {
			if (word1==word2)
				res=(i==j)? res: min(res,abs(mp[word1][i]-mp[word2][j]));
			else
				res=min(res,abs(mp[word1][i]-mp[word2][j]));
		}
		return res;
	}
};
int main(){
	vector<string> words{"practice", "makes", "perfect", "coding", "makes"};
	WordDistance s(words);
	cout << s.shortest("makes", "coding") << ' ' << s.shortest2(words, "makes", "coding") <<endl;
	cout << s.shortest("makes", "makes") << ' ' << s.shortest2(words, "makes", "makes") << endl;
}
