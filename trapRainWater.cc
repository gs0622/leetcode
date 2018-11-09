/* https://leetcode.com/problems/trapping-rain-water/description/
hint: monotonous decrease stack
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int trap1(vector<int>& A) {
		int i=0, n=A.size(), res=0;
		stack<int> stk;
		while (i<n) {
			if (stk.empty() || A[i]<=A[stk.top()])
				stk.push(i++);	// defer
			else {	// A[i] > A[stk.top()]
				int bot = stk.top(); stk.pop();	// trick: the 1st one is ether a L wall or nothing
				if (!stk.empty())		// empty means no left wall
					res += (min(A[stk.top()],A[i])-A[bot])*
					(i-stk.top()-1);	// think why i-stk.top()-1, L/R boundries are excluded
			}

		}
		return res;
	}
	// O(n) time, O(1) space
	int trap(vector<int>& A) {
		int L=0, R=A.size()-1;
		int maxL=0, maxR=0, res=0;
		while (L<=R) {
			if (A[L]<=A[R]) {
				if (A[L]>=maxL) maxL=A[L];
				else res+=maxL-A[L];		// cap by maxL > A[L] < A[R]
				++L;
			} else { // A[L]>A[R]
				if (A[R]>=maxR) maxR=A[R];
				else res+=maxR-A[R];		// cap by A[L] > A[R] < maxR
				--R;
			}
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<int> nums{0,1,0,2,1,0,1,3,2,1,2,1};
	cout << s.trap(nums) << ": " << s.trap1(nums) << endl;
}
