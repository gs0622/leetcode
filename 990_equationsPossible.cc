#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
	bool equationsPossible(vector<string>& equations) {
		int parents[256];
		for (int i=0; i<256; ++i) parents[i]=i;	// init
		function<int(int)> find=[&](int a) {
			if (parents[a]==a) return a;	// base case
			return find(parents[a]);	// recursive find parent
		};
		function<void(int,int)> uni=[&](int a, int b) {
			int roota=find(a), rootb=find(b);
			if (roota!=rootb) parents[a]=b;
		};
		for (string s: equations) {		// union
			if (s[1]=='=') uni(s[0],s[3]);
		}
		for (string s: equations) {		// validate
			if (s[1]=='!')
				if (find(s[0])==find(s[3]))
					return false;
		}
		return true;				// pass validation
	}
};

class Solution {
	class UF {
		//unordered_map<char,char> parent;
		map<char,char> parent;
		int groups;
	public:
		UF() {
			for (char ch='a'; ch<='z'; ++ch) parent[ch]=ch;
			groups = 26;
		}
		char find(char ch) {
			if (parent[ch]==ch) return ch;	// base case
			return find(parent[ch]);	// recursive find parent
		}
		void uni(char a, char b) {
			char ga = find(a), gb = find(b);
			if (ga != gb) parent[ga] = gb, --groups;
		}
	};
public:
	bool equationsPossible(vector<string>& equations) {
		UF uf;
		for (string s: equations)	// untion all "=="
			if (s[1]=='=') uf.uni(s[0],s[3]);
		for (string s: equations)	// validate all "!="
			if (s[1]=='!')
				if (uf.find(s[0])==uf.find(s[3]))
					return false;
		return true;
	}
};
int main(){
	Solution s;
	vector<string> e1{"a==b","b!=a"};
	cout << s.equationsPossible(e1) << endl;
	vector<string> e2{"f==a","a==b","f!=e","a==c","b==e","c==f"};
	cout << s.equationsPossible(e2) << endl;
}
