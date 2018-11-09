#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
		if (1==numRows) return s;
		vector<string> rows(numRows);
		for (int i=0,j=0,k; i<s.size(); ++i) {  // O(s.size())
			rows[j]+=s[i];
			if (j==0) k=1;			// bouncing in between
			else if (j==numRows-1) k=-1;
			j+=k;
		}
		string res;
		for (auto r: rows) res+=r;
		return res;
    }
};
int main(){
	Solution s;
	cout << s.convert("PAYPALISHIRING", 3) << endl;
	cout << s.convert("PAYPALISHIRING", 4) << endl;
}
