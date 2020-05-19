/* https://leetcode.com/problems/word-search-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;
class TrieNode {
public:
  bool eow;
  vector<TrieNode*> next;
  TrieNode(): eow(false), next(26,nullptr) {}
};
class Trie {
  TrieNode *root;
public:
  Trie(vector<string>& words) {
    root=new TrieNode();
    for (auto w: words) add(w);
  }
  TrieNode* getRoot() { return root; }
  void add(const string& word) {
    TrieNode *cur=root;
    for (int i=0; i<word.size(); ++i) {
      int idx=word[i]-'a';
      if (cur->next[idx]==nullptr)
        cur->next[idx]=new TrieNode();
      cur=cur->next[idx];
    }
    cur->eow=true;
  }
};
class Solution1 {
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    int m=board.size(),n=board[0].size();
    set<string> res;
    Trie trie(words);
    TrieNode* root=trie.getRoot();
    string s;
    function<void(int,int,TrieNode*)> helper=[&](int i, int j, TrieNode* cur) {
      if (i<0||i>=m||j<0||j>=n) return;
      if (board[i][j]<0) return;
      char ch=board[i][j];
      if (cur->next[ch-'a']) {
        s+=ch, board[i][j]^=-1;
        cur=cur->next[ch-'a'];
        if (cur->eow) res.insert(s);
        helper(i+1,j,cur),helper(i-1,j,cur),helper(i,j+1,cur),helper(i,j-1,cur);
        s.pop_back(),board[i][j]^=-1;
      }
    };
    for (int i=0;i<m;++i) for (int j=0;j<n;++j)
      helper(i,j,root);
  return vector<string>(res.begin(),res.end());
  }
};
class Solution {
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    int m=board.size(),n=board[0].size();
    unordered_set<string> st(words.begin(),words.end());
    set<string> res;
    string ans;
    function<void(int,int,int)> helper=[&](int i, int j, int k){
      if (st.count(ans)) {
        res.insert(ans);
        return;
      }
      if (i<0||i>=m||j<0||j>=n) return;
      ans+=board[i][j],board[i][j]^=-1;
      for (auto ss: st) {
        if (ss.substr(0,k+1)==ans)
          helper(i+1,j,k+1),helper(i-1,j,k+1),helper(i,j+1,k+1),helper(i,j-1,k+1);
      }
      ans.pop_back(),board[i][j]^=-1;
    };
    for (int i=0;i<m;++i) for (int j=0;j<n;++j)
      helper(i,j,0);
    return vector<string>(res.begin(),res.end());
  }
};
int main(){
  Solution1 s;
  vector<vector<char>> B1{{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
  vector<string> W1{"oath","pea","eat","rain"};
  for (auto ss: s.findWords(B1,W1)) cout << ss << " ";
  cout << endl;

  vector<vector<char>> B2{{'a'}};
  vector<string> W2{"a"};
  for (auto ss: s.findWords(B2,W2)) cout << ss << " ";
  cout << endl;
}
