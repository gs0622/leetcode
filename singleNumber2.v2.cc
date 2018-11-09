#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ans = 0;
		for (int i=0; i<32; ++i) {
			int bitcnt = 0;
			for (auto v: nums) bitcnt += (v>>i & 1);
			ans |= (bitcnt % 3)<<i;
		}
		return ans;
	}
};
int main(){
	Solution s;
	vector<int> nums{1,1,1,2,3,3,3};
	cout << s.singleNumber(nums) << endl;
}
