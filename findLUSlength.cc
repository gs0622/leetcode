#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int findLUSlength(string a, string b) {
		if (a.compare(b) == 0) return -1;
		return max(a.size(), b.size());
	}
};
int main(){
	Solution s;
	cout << s.findLUSlength("aba", "cdc") << endl;
}
