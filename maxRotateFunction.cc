/* https://leetcode.com/problems/rotate-function/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// F(0)=0A +1B+2C+3D
	// F(1)=-1A+0B+1C+2D+3A
	int maxRotateFunction(vector<int>& A) {
		int sum=accumulate(begin(A),end(A), 0);
		int res, n=A.size(), sum1=0;
		for (int i=1; i<n; ++i) sum1+=i*A[i];
		res = sum1;
		for (int i=1; i<n; ++i) 
			sum1-=sum, sum1+=n*A[i-1], res = max(res, sum1);
		return res;
	}
};
int main(){
	Solution s;
	vector<int> nums{4,3,2,6};
	cout << s.maxRotateFunction(nums) << endl;
}
