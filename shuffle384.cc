#include <bits/stdc++.h>
using namespace std;
class Solution {
	vector<int> cp1, cp2;
public:
	Solution(vector<int> nums) {
		if (nums.empty()) return;
		srand(time(0));
		cp1 = nums, cp2 = nums;
	}
	vector<int> reset() {
		return cp1;
	}
	vector<int> shuffle() {
		if (cp1.empty()) return {};
		random_shuffle(begin(cp2), end(cp2));
		return cp2;
	}
};
int main(){
	vector<int> nums{1,2,3};
	Solution s(nums);
	vector<int> res;
	res = s.shuffle();
	res = s.shuffle();
	res = s.shuffle();
	res = s.reset();
}
