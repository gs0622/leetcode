/* https://leetcode.com/problems/rotate-string/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool rotateString(string A, string B) {
		return A.size()==B.size() && (A+A).find(B) != string::npos;
	}
};
int main(){
	Solution s;
	string A1{"abcde"}, B1{"cdeab"};
	cout << s.rotateString(A1, B1) << endl;
	string A2{"aa"}, B2{"a"};
	cout << s.rotateString(A2, B2) << endl;
}
