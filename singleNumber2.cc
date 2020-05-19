/*
https://leetcode.com/problems/single-number-ii
Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	// O(n) time, O(1) space
	int singleNumber(vector<int>& nums) {
		int ones = 0, twos = 0;
		for (auto n: nums) {
			ones = ones ^ n & ~twos; // first appear
			twos = twos ^ n & ~ones;
		}
		return ones;
	}
	// O(32n) time, O(1) space
	int singleNumber2(vector<int>& nums) {
		int cnt, res = 0;
		for (int i = 0; i < 32; i++) {
			cnt = 0;
			for (auto x: nums) {
				cnt += ((unsigned int)x >> i) & 1;
		    
			}
			res = res | ((cnt % 3) << i);
		}
		return res;
	}
};

int main(void)
{
    int a[] = {1, 1, 1, 2, 2, 2, 3}; 
    std::vector<int> v(a, a+7);
    Solution s;
    std::cout << s.singleNumber(v) << " " << s.singleNumber(v) << endl;
    return 0;
}
