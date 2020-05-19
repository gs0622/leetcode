/* https://leetcode.com/problems/string-without-aaa-or-bbb/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
	string strWithout3a3b(int A, int B, char a='a', char b='b'){
		if (B>A) return strWithout3a3b(B,A,'b','a'); 
		string res;
		while (A>0){
			res+=a, --A;
			if (A>B) res+=a, --A;
			if (B>0) res+=b, --B;
		}
		return res;
	}
};
int main(){
	Solution s;
	cout << s.strWithout3a3b(1,2) << endl;
	cout << s.strWithout3a3b(4,1) << endl;
	cout << s.strWithout3a3b(4,2) << endl;
	cout << s.strWithout3a3b(4,3) << endl;
}
