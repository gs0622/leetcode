#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	bool checkRecord(string s) {
		int a=0, l=0; // no more than one 'A', no more than two continuous 'L'
		for (int i=0; i<s.size(); ++i) {
			if (s[i]=='A') a++;
			if (s[i]=='L') l++;
			else l=0; // reset while 'A'
			if (a>1 | l>2) return false;
		}
		return true;
	}
};
int main(){
	Solution s;
	//cout << s.checkRecord("PPALLP") << endl;
	//cout << s.checkRecord("PPALLL") << endl;
	cout << s.checkRecord("LALL") << endl;
}
