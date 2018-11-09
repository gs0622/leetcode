#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int lengthOfLastWord(string s) {
		while (s.back()==' ') s.erase(s.end()-1); // remove tailing space
		int pos = s.find_last_of(' ');
		return (pos==string::npos)? s.size(): s.substr(pos+1).size();
	}
};
int main(){
	Solution s;
	string s0 {"Hello World"};
	cout << s.lengthOfLastWord(s0) << endl;
	string s1 {"a "};
	cout << s.lengthOfLastWord(s1) << endl;
	string s2 {""};
	cout << s.lengthOfLastWord(s2) << endl;
}
