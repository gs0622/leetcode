/* https://leetcode.com/problems/basic-calculator/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int calculate(string s) {
		int res=0, num=0, sign=1;
		stack<int> stk;
		for (int i=0; i<s.size(); ++i) {
			int ch = s[i];
			if (isdigit(ch)) num=10*num+(s[i]-'0');
			else if (ch=='+') res+=sign*num, sign=1, num=0;
			else if (ch=='-') res+=sign*num, sign=-1, num=0;
			else if (ch=='(') stk.push(res), stk.push(sign), sign=1, res=0;
			else if (ch==')') res+=sign*num, res*=stk.top(), stk.pop(), res+=stk.top(), stk.pop(), num=0, sign=1;
		}
		if (num!=0) res+=sign*num;
		return res;
	}
};
int main(){
	Solution s;
	cout << s.calculate("1 + 1") << endl;
	cout << s.calculate(" 2-1 + 2 ") << endl;
	cout << s.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
}
