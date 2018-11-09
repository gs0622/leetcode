#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ret(2,-1);
		int mi, lo=0, hi=nums.size()-1;
		while (lo<=hi) {
			mi = lo+(hi-lo)/2;
			if (nums[mi] > target)
				hi=mi-1;
			else if (nums[mi] < target)
				lo=mi+1;
			else // nums[mi] == target;
				break;
		}
		if (lo <= hi) {
			lo = mi, hi=mi;
			while (nums[lo-1] == target && lo-1>=0) lo-=1;
			while (nums[hi+1] == target && hi+1<=nums.size()) hi+=1;
			ret[0]=lo, ret[1]=hi;
		}
		return ret;
	}
	vector<int> searchRange2(vector<int>& nums, int target) {
		vector<int> ret(2,-1);
		for (int i=0; i<nums.size(); ++i) {
			if (nums[i] == target) {
				ret[0] = i;
				while (nums[i+1] == target && i+1 < nums.size())
					i+=1;
				ret[1] = i;
			}
		}
		return ret;
	}
};
int main(){
	vector<int> nums{5, 7, 7, 8, 8, 10};
	vector<int> res;
	Solution s;
	res = s.searchRange(nums, 8);
	for (auto x: res) cout << x << " ";
	cout << endl;
}
