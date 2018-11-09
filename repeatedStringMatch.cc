#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(m*n): m=A.size(), n=B.size()
	int repeatedStringMatch(string A, string B) {
		for (int i=0, j; i<A.size(); ++i) {
			for (j=0; j<B.size(); ++j) {
				if (A[(i+j)%A.size()]!=B[j]) break;	// ++i then restart j=0 matching, (i+j)%A.size() imply repeat 
			}
			if (j==B.size()) return (i+j)/A.size() + ((i+j)%A.size()!=0);
		}
		return -1;
	}
};
int main(){
	Solution s;
	cout << s.repeatedStringMatch("abcd", "cdabcdab") << endl;
	cout << s.repeatedStringMatch("abcde", "cdabcdab") << endl;
	cout << s.repeatedStringMatch("abcd", "cdab") << endl;
}
