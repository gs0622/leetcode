#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
	// dfs helper
	void helper(int left, int right, string str, vector<string>& ret) {
		if (right == 0) {
			ret.push_back(str);
			return;
		}
		if (left > 0) helper(left-1, right, str+'(', ret);
		if (right > left) helper(left, right-1, str+')', ret);
	}
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ret;
		helper(n, n, "", ret);
		return ret;
	}
};

int main(){
	vector<string> ret;
	Solution s;
	ret = s.generateParenthesis(3);
	for (auto s: ret) cout << s << endl;
	ret.clear();
	ret = s.generateParenthesis(4);
	for (auto s: ret) cout << s << endl;
}
