#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int totalHammingDistance(vector<int>& nums) {
		int i, j, k, bitcnt, dist=0, n = nums.size();
		for (i=0; i<32; ++i) {
			bitcnt=0;
			for (j=0; j<n; ++j) bitcnt += (nums[j] >> i) & 1;
			dist += bitcnt * (n-bitcnt); 
		}
		return dist;
	}
	int totalHammingDistance2(vector<int>& nums) {
		int i, j, x, dist = 0, sz = nums.size();
		for (i=0; i<sz; ++i) {
			for (j=i+1; j<sz; ++j) {
				x = nums[i]^nums[j];
				//cout << x << endl;
				while (x) {
					x &= x-1; // clean the lowest bit
					dist += 1;
				}
			}
		}
		return dist;
	}
};
int main(){
	Solution s;
	vector<int> nums{4,14,2};
	cout << s.totalHammingDistance(nums) << " " << s.totalHammingDistance2(nums) << endl;
}
