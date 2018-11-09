/*
https://leetcode.com/problems/single-number
Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		std::unordered_set<int> s;			// O(n) space
		for (auto& v: nums) {
			if (s.find(v) != s.end()) s.erase(v);	// 2nd appreance
			else s.insert(v);
		}
		return *s.begin();
	}
};

int main(void)
{
	int a[] = {1, 1, 2, 3, 3};
	std::vector<int> v(a, a+5);
	Solution s;
	std::cout << s.singleNumber(v) << endl;
	return 0;
}
