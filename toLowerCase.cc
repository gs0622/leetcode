#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// A-Z are smaller than a-z in ASCIO
	string toLowerCase(string str) {
		for (auto& c: str) if (c>='A'&&c<='Z') c+='a'-'A';	// c=c-'A'+'a'
		return str;
	}
};
int main(){
	Solution s;
	cout << s.toLowerCase("Hello") << endl;
	cout << s.toLowerCase("here") << endl;
	cout << s.toLowerCase("LOVELY") << endl;
}
