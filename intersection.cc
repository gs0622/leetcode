#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		multiset<int> myset(nums1.begin(), nums1.end());
		vector<int> res;
		for (auto n: nums2) {
			auto it = myset.find(n);
			if (it != myset.end()) {
				res.push_back(n);
				myset.erase(it);	// don't erase n, use iterator
			}
		}
		return res;
	}
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> um1, um2;
		vector<int> ans;
		if (0 == nums1.size() || 0 == nums2.size()) return ans;
		for (auto x: nums1)
			um1[x]++;
		for (auto y: nums2)
			um2[y]++;

		for (auto z: nums1) {
			if (um2.find(z) != um2.end()) {
				while ((um1[z] > 0) && (um2[z] > 0)) {
					ans.push_back(z);
					um1[z]--;
					um2[z]--;
				}
			}
		}	
		return ans;
    }   
};
int main(){
	Solution s;
	vector<int> nums1{1,2,2,1};
	vector<int> nums2{2,2};
	vector<int> res = s.intersection(nums1, nums2);
	for_each(begin(res), end(res), [](int n){cout << n << ' ';}); cout << endl;
}
