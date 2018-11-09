/* https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
Could you do this in O(n) runtime?
*/
#include <climits>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
	int findMaximumXOR(vector<int>& nums) {
		int i, mask = 0, res = 0;
		for (i=31; i>=0; --i) {
			mask |= 1 << i;		// bit-by-bit from MSB to LSB
			unordered_set<int> prefixes;
			cout << std::dec << i << ": ";
			for (auto num: nums) {
				cout << std::hex << num << " & " << mask <<" (" << (mask & num) << ") ";
				prefixes.insert(mask & num);
			}
			cout << endl;
			int tmp = res | (1 << i); // build max from bit-by-bit
			for (auto prefix: prefixes) {
				if (prefixes.count(tmp ^ prefix) > 0) {
					cout << std::hex << tmp << ": " << prefix << ": " << res << " ";
					res = tmp;
					break;
				}
			}
			cout << endl;
		}
		return res;
	}
	// Still O(n^2) brute-force
	int findMaximumXOR2(vector<int>& nums) {
		int i, j, n = nums.size(), res = 0;
		unordered_set<int> m(nums.begin(), nums.end());
		for (auto a: m) {
			for (auto b: m) {
				res = std::max(res, a^b);
			}
		}
		return res;
	}
	// O(n^2) brute-force
	int findMaximumXOR3(vector<int>& nums) {
		int i, j, n = nums.size(), res = 0;
		for (i=0; i<n; ++i) {
			for (j=i+1; j<n; ++j) {
				res = std::max(res, nums[i]^nums[j]);		
			}
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<int> nums{3, 10, 5, 25, 2, 8};
	//vector<int> nums{0};
	cout << s.findMaximumXOR(nums) << " " << s.findMaximumXOR2(nums) << endl;
}
