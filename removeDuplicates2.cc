/* https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
hint: two pointers
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(1) space in-place
	int removeDuplicates1(vector<int>& nums) {
		int i=0;
		for (int n: nums) {
			if (i<2 || n>nums[i-2])	// when the dup window grows larger than two, i stops until non-repeat
				nums[i++] = n;
		}
		nums.resize(i);
		return i;
	}
	// O(n) space brute-force
	int removeDuplicates(vector<int>& nums) {
		map<int,int> mymap; //key,cnt map
		for (auto n: nums) ++mymap[n];
		vector<int> res;
		for (auto it=begin(mymap); it!=end(mymap); ++it) {
			int i=0;
			while (it->second) {
				if (i>=2) break;
				res.push_back(it->first);
				++i, --(it->second);
			}
		}
		nums.swap(res);
		return nums.size();
	}
};
int main(){
	Solution s;
	vector<int> nums1{1,1,1,2,2,3};
	int len = s.removeDuplicates1(nums1);
	cout << len << endl;
	for_each(begin(nums1), end(nums1), [](int n){cout<<n<<' ';}); cout << endl;
	vector<int> nums2{0,0,1,1,1,2,3,3};
	len = s.removeDuplicates1(nums2);
	cout << len << endl;
	for_each(begin(nums2), end(nums2), [](int n){cout<<n<<' ';}); cout << endl;
}
