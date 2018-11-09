#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
	// O(n)
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int,int> m;	// key/idx map
		int i, n=nums.size();
		for (i=0; i<n; ++i)		// Q: does the order matter?
			m[nums[i]]=i;
		for (i=0; i<n; ++i) {
			auto it = m.find(target-nums[i]);
			if (it != m.end() && i != it->second) {
				return vector<int>{i, m[target-nums[i]]};
			}
			//m[nums[i]]=i;
		}
		return vector<int>();		// not found
	}   
};
int main(){
	Solution s;
	vector<int> nums1{2, 7, 11, 15};
	vector<int> ret = s.twoSum(nums1, 9);
	for (auto x: ret) cout << x << " ";
	cout << endl;
	vector<int> nums2{3,2,4};
	ret = s.twoSum(nums2, 6);
	for (auto x: ret) cout << x << " ";
	cout << endl;
}
