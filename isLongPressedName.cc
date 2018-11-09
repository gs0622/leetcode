#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isLongPressedName1(string name, string typed) {
		int i=0, j=0;
		while (j<typed.size()) {
			if (name[i]==typed[j]) ++i, ++j;		// case-1: step both pointers
			else if (i>0 && name[i-1]==typed[j]) ++j;	// case-2: dup of name[i-1], step j
			else return false;				// other: fail
		}
		return i==name.size();
	}
	bool isLongPressedName(string name, string typed) {
		int i=0;
		for (auto c: typed) i+=(c==name[i]);
		return i==name.size();
	}
};
int main(){
	Solution s;
	cout << s.isLongPressedName1("alex", "aaleex") << endl;
	cout << s.isLongPressedName1("saeed", "ssaaedd") << endl;
	cout << s.isLongPressedName1("leelee", "lleeelee") << endl;
	cout << s.isLongPressedName1("laiden", "laiden") << endl;
}
