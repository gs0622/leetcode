/* https://leetcode.com/problems/different-ways-to-add-parentheses/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> diffWaysToCompute(string in) {
		vector<int> res;
		for (int i=0; i<in.size(); ++i) {	// tricky: this enumerates all breaks of strings
			int ch = in[i];
			if (ch=='+'||ch=='-'||ch=='*') {
				vector<int> L, R;
				L = diffWaysToCompute(in.substr(0, i));
				R = diffWaysToCompute(in.substr(i+1));
				for (auto x: L) {	// postorder eval
					for (auto y: R) {
						if (ch=='+') res.push_back(x+y);
						else if (ch=='-') res.push_back(x-y);
						else res.push_back(x*y);
					}
				}
			}
		}
		if (res.empty())
			res.push_back(stoi(in));
		return res;
	}
};
int main(){
	Solution s;
	vector<int> res;
	string s1{"2-1-1"};
	//string s1{"2*3-4*5"};
	res = s.diffWaysToCompute(s1);
	copy(begin(res), end(res), ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << endl;
}
