#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool detectCapitalUse(string s) {
		bool tp1=true, tp2=true, tp3=true;	// all lower, cap first, all upper
		for (auto c: s) if (c<'a' || c>'z') tp1=false;
		if (s[0]>='A' && s[0]<='Z') {
			for (int i=1; i<s.size(); ++i) {
				int c=s[i];
				if (c<'a' || c>'z') tp2=false;
				if (c<'A' || c>'Z') tp3=false;
			}
		} else tp2=false, tp3=false;
		return tp1 || tp2 || tp3;
	}
};
int main(){
	Solution s;
	//cout << s.detectCapitalUse("USA") << endl;
	//cout << s.detectCapitalUse("FlaG") << endl;
	//cout << s.detectCapitalUse("Google") << endl;
	cout << s.detectCapitalUse("ffffffffffffffffffffF") << endl;
}
