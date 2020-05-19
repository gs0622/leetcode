#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string shiftingLetters(string S, vector<int>& shifts) {
		int n=S.size(), m=shifts.size();
		for (int i=0; i<m; ++i) {
			for (int j=0; j<=i; ++j) {
				S[j] = (S[j]-'a'+shifts[i])%26 + 'a';
			}
		}
		return S;
	}
};
int main(){
	Solution s;
	vector<int> S1{3,5,9};
	cout << s.shiftingLetters("abc", S1) << endl;
}
