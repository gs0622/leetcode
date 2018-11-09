/* https://leetcode.com/problems/optimal-division/description/
Given a list of positive integers, the adjacent integers will perform the float division. For example, [2,3,4] -> 2 / 3 / 4.

However, you can add any number of parenthesis at any position to change the priority of operations.
You should find out how to add parenthesis to get the maximum result, 
and return the corresponding expression in string format.
Your expression should NOT contain redundant parenthesis.

Hint in terms of math:
X1/X2/X3/../Xn will always be equal to (X1/X2) * Y, no matter how you place parentheses.
i.e no matter how you place parentheses, X1 always goes to the numerator and X2 always goes to the denominator.
Hence you just need to maximize Y.
And Y is maximized when it is equal to X3 *..*Xn.
So the answer is always X1/(X2/X3/../Xn) = (X1 *X3 *..*Xn)/X2

e.g.,
1000/(100/10/2) = 200

Other cases:
1000/(100/10)/2 = 50
1000/(100/(10/2)) = 50
1000/100/10/2 = 0.5
1000/100/(10/2) = 2
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string optimalDivision(vector<int>& nums) {
		if (nums.empty()) return "";
		string res = to_string(nums[0]);
		if (nums.size()==1) return res;
		if (nums.size()==2) return res + "/"+to_string(nums[1]);
		res += "/(";
		for (int i=1; i<nums.size(); ++i) {
			res += to_string(nums[i]);
			if (i != nums.size()-1) res += "/";
		}
		res += ")";
		return res;
	}
};
int main(){
	vector<int> nums{1000,100,10,2};
	Solution s;
	cout << s.optimalDivision(nums) << endl;
}
