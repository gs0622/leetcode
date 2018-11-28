#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int first, second, third, sum;
		int sz = nums.size();
		if (sz < 3) return 0;
		std::sort(nums.begin(), nums.end());
		int closest = nums[0] + nums[1] + nums[2];
		for (first = 0; first < sz-2; first++) {
			second = first+1, third = sz-1;
			while (third > second) {
				sum = nums[first] + nums[second] + nums[third];
				if (sum == target) return sum;
				if (std::abs(closest - target) > std::abs(sum - target))
					closest = sum;
				if (sum < target) second+=1;
				else third-=1;
			}
		}
		return closest;
	}
	int threeSumClosest2(vector<int>& nums, int target) {
		int i, j, k, sum;
		int sz = nums.size();
		if (sz < 3) return 0;
		int closest = nums[0] + nums[1] + nums[2];
		for (i = 0; i < sz-2; i++) {
			for (j = i+1; j < sz-1; j++) {
				for (k = j+1; k < sz; k++) {
					sum = nums[i] + nums[j] + nums[k];
					if (sum == target) return sum;
					if (std::abs(closest - target) > std::abs(sum - target))
						closest = sum;
				}
			}
		}
		return closest;
	}
};

int main() {
	vector<int> S1 {-1, 2, 1, -4};
	vector<int> S2 {1, 1, -1};
	Solution s;
	cout << s.threeSumClosest(S1, 1) << ": ";
	cout << s.threeSumClosest2(S1, 1) << endl;
	cout << s.threeSumClosest(S2, 2) << ": ";
	cout << s.threeSumClosest2(S2, 1) << endl;
}
