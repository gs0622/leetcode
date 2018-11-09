#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isValidSerialization(string S) {
		istringstream t(S);
		string tmp;
		int cap = 1;
		while (getline(t, tmp, ',')) {
			if (--cap < 0)
				return false;
			if (tmp!="#")			// non-null node allows two children
				cap+=2;
		}
		return cap==0;
	}
};
int main(){
	Solution s;
	string s1{"9,3,4,#,#,1,#,#,2,#,6,#,#"};
	string s2{"1,#"};
	string s3{"9,#,#,1"};
	//cout << s.isValidSerialization(s1) << endl; 
	cout << s.isValidSerialization(s2) << endl; 
	cout << s.isValidSerialization(s3) << endl; 
}
