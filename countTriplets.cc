#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
	// O(n^2)
	int countTriplets(vector<int>& nums) {
		int i, j, x, cnt=0, sz=nums.size();
		unordered_set<int> s;
		for (i=0; i<sz; ++i) s.insert(nums[i]); 
		for (i=0; i<sz; ++i) {
			for (j=i+1; j<sz; ++j) {
				x = nums[i]^nums[j];
				if (x == nums[i] || x == nums[j]) continue;
				if (s.count(x) == 1) {
					//cout << nums[i] << " " << nums[j] << " " << x << endl;
					cnt+=1;
				}
			}
		}
		return cnt/3;
	}
	// O(n^3)
	int countTriplets2(vector<int>& nums) {
		int i, j, k, cnt = 0, sz=nums.size();
		for (i=0; i<sz; ++i) {
			for (j=i+1; j<sz; ++j) {
				for (k=j+1; k<sz; ++k) {
					if ((nums[i]^nums[j]^nums[k]) == 0) {
						//cout << nums[i] << " " << nums[j] << " " << nums[k] << endl;
						cnt+=1;
					}
				}	
			}
		}
		return cnt;
	}
};
int main(){
	Solution s;
	vector<vector<int>> nums{{0, 1, 3, 5, 10, 14, 15},{4, 7, 5, 8, 3, 9}};
	for (auto n: nums)
		cout << s.countTriplets(n) << " " << s.countTriplets2(n) << endl;
}
