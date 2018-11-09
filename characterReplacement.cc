#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// sliding window
	int characterReplacement(string s, int k) {
		int ch[26]={}, i=0, j=0;
		while (j<s.size()) {
			ch[s[j++]-'A']++;
			if (j-i -*max_element(ch, ch+26) > k)
				ch[s[i++]-'A']--;
		}
		return j-i;
	}
};

int main(){
	Solution s;
	string ss;
	int k;
	cin >> ss >> k;
	cout << s.characterReplacement(ss, k) << endl;
}
