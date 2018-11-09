/* https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		map<int,int> mymap;			// keep the keys sorted
		for (auto n: nums) ++mymap[n];
		int res = 0;
		for (auto p: mymap) {
			if ((k==0 && p.second > 1) || (k!= 0 && mymap.find(p.first+k) != end(mymap)))
				++res;
			mymap.erase(begin(mymap));	// erase smaller ones for negative k
		}
		return res;
	}
};
using namespace std;
int main(){
	Solution s;
	vector<int> nums1{3,1,4,1,5};
	//cout << s.findPairs(nums1, 2) << endl;
	vector<int> nums2{1,2,3,4,5};
	//cout << s.findPairs(nums2, 1) << endl;
	cout << s.findPairs(nums2, -1) << endl;
	vector<int> nums3{1,3,1,4,5};
	//cout << s.findPairs(nums3, 0) << endl;
}
