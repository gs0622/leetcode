/* https://leetcode.com/problems/largest-rectangle-in-histogram/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int largestRectangleArea(vector<int>& nums) {
		int res=0;
		stack<int> stk;			    // bar index stack
		nums.push_back(0);			// sentinel in right side
		for (int i=0; i<nums.size(); ++i) {
			while (!stk.empty() && nums[stk.top()] >= nums[i]) {	// 'while' makes it calculate all decending rectangle by means of top
				int H = nums[stk.top()]; stk.pop();		// this height
				int L = stk.empty()? -1: stk.top();		// this left
				int area = H * (i-L-1);				// triky: width is calculated by indices
				res = max(res, area);
			}
			stk.push(i);						// save x coordinate, defer to later
		}
		return res;
	}
};
int main(){
	Solution s;
	//vector<int> nums{2,1,5,6,2,3};
	//vector<int> nums{2,1,5,6,2,3,9,10};
	//vector<int> nums{3,4,5};
	vector<int> nums{0,9};
	cout << s.largestRectangleArea(nums) << endl;
}
