#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		if (tokens.empty()) return 0;
		stack<int> stk;
		for (auto s: tokens) {
			if (s.size() == 1 && ispunct(s[0])) {
				int y = stk.top(); stk.pop();	// 2nd operand
				int x = stk.top(); stk.pop();	// 1st one
				if (s == "+")
					stk.push(x+y);
				else if (s == "-")
					stk.push(x-y);
				else if (s == "*")
					stk.push(x*y);
				else if (s == "/")
					stk.push(x/y);
			} else
				stk.push(stoi(s));
		}
		return stk.top();
	}
};
int main(){
	Solution s;
	vector<string> s1{"2", "1", "+", "3", "*"};
	//cout << s.evalRPN(s1) << endl;
	vector<string> s2{"4", "13", "5", "/", "+"};
	//cout << s.evalRPN(s2) << endl;
	vector<string> s3{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
	cout << s.evalRPN(s3) << endl;
}
