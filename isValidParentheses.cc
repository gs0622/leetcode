#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
    bool isValid(string& s, int& i, stack<char>& ss) {
		if (i == s.size() - 1) return true;
		char c = s[i];
		switch (c) {
		case ')':
			if (ss.top() != '(') return false;
			ss.pop();
			break;
		case '}':
			if (ss.top() != '{') return false;
			ss.pop();
			break;
		case ']':
			if (ss.top() != '[') return false;
			ss.pop();
			break;
		default:
			ss.push(s[i]);
		}
		i += 1;
		return isValid(s, i, ss);
	}
public:
	bool isValid(string s) {
		if (s.empty()) return true;
		int i = 0;
		std::stack<char> ss;
		return isValid(s, i, ss);
	}
};

int main() {
	std::string s1("{[()]}");
	std::string s2("{[(()]}");
	Solution s;
	cout << s.isValid(s1) << endl;
	cout << s.isValid(s2) << endl;
	return 0;
}
