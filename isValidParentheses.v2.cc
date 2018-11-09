#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
	std::unordered_map<char, char> m;
public:
	Solution() {
		m['('] = ')';
		m['{'] = '}';
		m['['] = ']';
	}
    bool isValid(string s) {
		std::stack<char> ss;
		for (char c: s) {
			auto it = m.find(c);
			if (it != m.end())		// push in the opposite key
				ss.push(it->second);
			else {
				if (ss.empty() || ss.top() != c)
					return false;
				ss.pop();
			}
		}
		return ss.empty();
    }
};

int main() {
	std::string s1("{[()]}");
	std::string s2("{[(()]}");
	std::string s3("[");
	Solution s;
	cout << s.isValid(s1) << endl;
	cout << s.isValid(s2) << endl;
	cout << s.isValid(s3) << endl;
	return 0;
}
