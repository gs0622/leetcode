#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <algorithm>
using namespace std;

class Solution {
public:
	string decodeString(string& s, int& i) {
		string res;
		int len = s.length();
		while (i < len && s[i] != ']') {
			if (!isdigit(s[i])) res += s[i++];
			else {
				int n = 0;
				while (i < len && isdigit(s[i]))
					n = n * 10 + (s[i++] - '0');
				i++; // '['
				string t = decodeString(s, i);
				i++; // ']'
				while (n-- > 0)
					res += t;
			}
		}
		return res;
	}
	string decodeString(string s) {
		int i = 0;
		return decodeString(s, i);
	}
};

int main(void)
{
	std::string s0("3[a]2[bc]");
	std::string s1("3[a2[c]]");
	std::string s2("2[abc]3[cd]ef");
	Solution s;
	std::cout << s.decodeString(s0) << endl;
	std::cout << s.decodeString(s1) << endl;
	std::cout << s.decodeString(s2) << endl;
	return 0;
}
