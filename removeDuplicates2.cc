/* https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
hint: two pointers
*/
#include <bits/stdc++.h>
using namespace std;
class Solution3 {
public:
	int removeDuplicates(vector<int>& nums, int k=2) {
    int i=0;
    for (auto n:nums)
      if (i<k || nums[i-k]!=n)
        nums[i++]=n;
    nums.resize(i);
    return i;
  }
};
class Solution2 {
public:
	int removeDuplicates(vector<int>& nums) {
    int L,R,n=nums.size();
    for (L=0,R=0; R<n; ++R) {
      if (L<2 || nums[L-2]!=nums[R])
        nums[L++]=nums[R];
      // else // nums[L]==nums[R]
    }
    nums.resize(L);
    return L;
  }
};
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
	Solution2 s;
	vector<int> nums1{1,1,1,2,2,3};
	int len = s.removeDuplicates(nums1);
	cout << len << endl;
	for_each(begin(nums1), end(nums1), [](int n){cout<<n<<' ';}); cout << endl;
	vector<int> nums2{0,0,1,1,1,2,3,3};
	len = s.removeDuplicates(nums2);
	cout << len << endl;
	for_each(begin(nums2), end(nums2), [](int n){cout<<n<<' ';}); cout << endl;
}
