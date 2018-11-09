#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int expressiveWords(string S, vector<string>& words) {
		int res=0;
		function<bool(int)> helper=[&](int id) {
			string W=words[id];
			int i,j;
			for (i=0,j=0; i<S.size(); ++i) {
				if (S[i]==W[j]) ++j;
				else if (i>0 && i+1<S.size() && S[i-1]==S[i] && S[i+1]==S[i]);	// 1st repeat
				else if (i>1 && S[i-2]==S[i] && S[i-1]==S[i]);			// 2nd repeat
				else
					return false;
			}
			return j==W.size();							// final examination
		};
		for (int i=0; i<words.size(); ++i)
			if (helper(i))
				++res;
		return res;	
	}
};
int main(){
	Solution s;
	vector<string> w1{"hello", "hi", "helo"};
	vector<string> w2{"aaaa"};
	cout << s.expressiveWords("heeellooo",w1) << endl;
	cout << s.expressiveWords("heeelllooo",w1) << endl;
	cout << s.expressiveWords("aaa",w2) << endl;
}
