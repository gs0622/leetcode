/* https://leetcode.com/problems/first-unique-character-in-a-string/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<char, int> m;
		int i, n=s.size();
		for (i=0; i<n; ++i) ++m[s[i]];
		for (i=0; i<n; ++i) {
			if (m[s[i]]==1) return i;
		}
		return -1;
	}
};
int main(){
	Solution s;
	string s1{"leetcode"};
	cout << s.firstUniqChar(s1) << endl;
	string s2{"loveleetcode"};
	cout << s.firstUniqChar(s2) << endl;
	string s3{"llleettccooddee"};
	cout << s.firstUniqChar(s3) << endl;
}
