#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		int i=0, n=nums.size();
		vector<string> res;
		while (i<n) {
			int s = nums[i];
			while (i+1<n && nums[i+1]-nums[i]==1) ++i;
			if (nums[i]==s) res.push_back(to_string(s));
			else res.push_back(to_string(s) + "->" + to_string(nums[i]));
			++i;
		}
		return res;
	}
	vector<string> summaryRanges2(vector<int>& nums) {
		int i, j, n=nums.size();
		if (n==0) return vector<string>();
		vector<int> aux(n,1);
		vector<string> res;
		for (i=1; i<n; ++i) aux[i]=nums[i]-nums[i-1];
		for (i=0, j=0; i<n && j<n; ++j) {
			while (j<n && aux[j]==1) ++j;
			if ((j-1)!=i) res.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));
			else res.push_back(to_string(nums[j-1]));
			i=j;
		}
		if ((j-1)!=i) res.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));
		else if (i<n) res.push_back(to_string(nums[i]));
		return res;
	}
};
int main(){
	Solution s;
	vector<string> res;
	vector<int> nums1{0,1,2,4,5,7};
	res = s.summaryRanges(nums1);
	for (auto x: res) cout << x << " ";
	cout << endl;
	vector<int> nums2{0,2,3,4,6,8,9};
	res = s.summaryRanges(nums2);
	for (auto x: res) cout << x << " ";
	cout << endl;
}
