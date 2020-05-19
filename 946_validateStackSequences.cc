#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(n) stack
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> stk;
		int j=0;//, n=popped.size();
		for (auto i: pushed) {
			stk.push(i);
			while (!stk.empty() && stk.top() == popped[j])
				stk.pop(), ++j;
		}
		//return j==n;
		return stk.empty();
	}
};
int main(){
	Solution s;
	vector<int> pushed1{1,2,3,4,5}, popped1{4,5,3,2,1};
	cout << s.validateStackSequences(pushed1, popped1) << endl; 
	vector<int> popped2{4,3,5,1,2};
	cout << s.validateStackSequences(pushed1, popped2) << endl; 
}
