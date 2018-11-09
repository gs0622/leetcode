#include <climits>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	// two pointers
	int minSubArrayLen(int s, vector<int>& nums) {
		int sum = 0, sz = nums.size();
		int i = 0, j = 0, ans = INT_MAX;
		for (i=0; i<sz; ++i) {
			sum += nums[i];
			while (sum >= s) {
				ans = std::min(ans, i-j+1);
				sum -= nums[j++];
			} 
		}
		return (ans == INT_MAX)? 0: ans;
	}
};
int main(){
	vector<int> nums {2,3,1,2,4,3};
	Solution s;
	cout << s.minSubArrayLen(7, nums) << endl;
}

