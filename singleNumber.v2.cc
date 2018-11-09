/*
https://leetcode.com/problems/single-number
Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
        std::unordered_map<int, int> m;
        for (auto x: nums) {
            m[x] += 1;
        }
        for (auto y: m) {
            if (y.second == 1)
                return y.first;
        }
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
