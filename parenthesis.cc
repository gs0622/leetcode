#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		stack<char> stk;
		for (int i=0; i<s.size(); ++i) {
			if (s[i] == '(') stk.push(')');
			else if (s[i] == '{') stk.push('}');
			else if (s[i] == '[') stk.push(']');
			else if (stk.empty() || s[i] == stk.top()) return false;
		}
		return s.empty();
	}
};
int isValid(char* s)
{ 
	char stack[1024576], c;
	unsigned int n = 0;
	while (c = *s) {
		if (c == '(') stack[n++] = ')';
		else if (c == '{') stack[n++] = '}';
		else if (c == '[') stack[n++] = ']';
		else if (n == 0 || stack[--n] != c) return 0;
		s += 1;
	}
	return (0 == n);
}

int main(int argc, char **argv)
{
	Solution s;
	cout << s.isValid("()") << endl;
	cout << s.isValid(")(") << endl;
	return 0;
}
