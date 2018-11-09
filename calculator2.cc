#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int calculate(string s) {
		int res=0, num=0, n=s.size();
		stack<int> stk;
		char op='+';
		for (int i=0; i<n; ++i) {
			if (isdigit(s[i]))
				num=10*num+(s[i]-'0');
			if (!isdigit(s[i]) && !isspace(s[i]) || i==n-1) {	// num fetching is done
				if (op=='+') stk.push(num);			// previous detected op
				else if (op=='-') stk.push(-num);
				else {
					int v=stk.top(); stk.pop();
					if (op=='*') stk.push(v*num);
					else stk.push(v/num);
				}
				num=0, op=s[i];
			}
		}
		while (!stk.empty())
			res+=stk.top(), stk.pop();
		return res;
	}
};
int main(){
	Solution s;
	cout << s.calculate("3+2*2") << endl;
	cout << s.calculate(" 3/2 ") << endl;
	cout << s.calculate(" 3+5 / 2") << endl;
}
