/*https://leetcode.com/problems/baseball-game/description/*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int calPoints(vector<string>& ops) {
		stack<int> pts;
		for (auto s: ops) {
			if (s == "C")
				pts.pop();
			else if (s == "D")
				pts.push(pts.top()*2);
			else if (s == "+") {
				int tmp1 = pts.top();
				pts.pop();
				int tmp2 = pts.top();
				pts.push(tmp1);
				pts.push(tmp1+tmp2);
			}
			else pts.push(stoi(s));
		}
		int score = 0;
		while (!pts.empty()) {
			score += pts.top();
			pts.pop();
		}
		return score;
	}
};
int main(){
	Solution s;
	vector<string> ops1{"5","2","C","D","+"};
	vector<string> ops2{"5","-2","4","C","D","9","+","+"};
	cout << s.calPoints(ops1) << endl;
	cout << s.calPoints(ops2) << endl;
}
