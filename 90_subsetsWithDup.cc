/* https://leetcode.com/problems/subsets-ii/description/
*/
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
class Solution {
public:
	vvi subsetsWithDup2(vi& nums) {
		vvi res;
		vi sub;
		int n=nums.size();
		function<void(int)> helper=[&](int i){
			res.push_back(sub);
			for (int j=i; j<n; ++j) {
				if (j>i && nums[j]==nums[j-1]) continue;	// for dup keys
				sub.push_back(nums[j]);
				helper(j+1);
				sub.pop_back();
			}
		};
		sort(nums.begin(), nums.end());		// O(nlog(n)), for dup keys
		helper(0);
		return res;
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(begin(nums), end(nums));
		vector<vector<int>> res{{}};
		int i,j,k,n,dup;
		for (i=0; i<nums.size(); i+=dup) {
			dup=1;	// at least 1;
			while (i+dup < nums.size() && nums[i+dup] == nums[i]) ++dup;
			n = res.size();
			for (j=0; j<n; ++j) {	// clone previous subset
				res.push_back(res[j]);
				res.back().push_back(nums[i]);
				for (k=1; k<dup; ++k) {
					res.push_back(res.back());
					res.back().push_back(nums[i]);
				}
			}
		}
		return res;
	}
	vector<vector<int>> subsetsWithDup1(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		vector<vector<int>> res{{}};
		for (int i=0, cnt; i<nums.size(); i+=cnt) {
			cnt=0; // dup count
			while (cnt+i < nums.size() && nums[cnt+i]==nums[i]) cnt++;
			int n = res.size();
			for (int j=0; j<n; ++j) {
				vector<int> tmp=res[j];
				for (int k=0; k<cnt; ++k) {
					tmp.push_back(nums[i]);
					res.push_back(tmp);
				}
			}
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<int> nums{1,2,2};
	vector<vector<int>> res = s.subsetsWithDup2(nums);
	for (auto x: res) {
		for (auto y: x) cout << y << " ";
		cout << endl;
	}
}
