/* 
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> searchRange4(vector<int>& nums, int target) {
		vector<int> res(2,-1);
		int n=nums.size(), lo=0, hi=n-1;
		while (lo<hi) {
			int mi=lo+(hi-lo)/2;
			if (nums[mi]<target) lo=mi+1;	// cut left half
			else hi=mi;			// cut right half
		} // lo==hi then
		if (nums[lo]!=target) return res;	// not found;
		res[0]=lo, hi=n-1;
		while (lo<=hi) {
			int mi=lo+(hi-lo)/2;
			if (nums[mi]>target) hi=mi-1;	// cut right half
			else lo=mi+1;
		} // lo>hi
		res[1]=lo-1;
		return res;
	}
	// O(log(n))
	vector<int> searchRange3(vector<int>& nums, int target) {
		auto b = equal_range(begin(nums), end(nums), target);	// get lower and upper bound
		if (b.first == b.second) return {-1, -1};		// the bounds won't be the same unless not found
		return {(int)distance(begin(nums), b.first), (int)distance(begin(nums), b.second-1)};
	}
	// O(log(n))
	vector<int> searchRange2(vector<int>& nums, int target) {
		vector<int> res(2,-1);
		auto lower = lower_bound(nums.begin(), nums.end(), target);
		if (lower == nums.end()) return res;
		auto upper = upper_bound(nums.begin(), nums.end(), target);
		res[0] = distance(begin(nums), lower);
		res[1] = distance(begin(nums), upper-1);
		return res;
	}
	// O(n)
	vector<int> searchRange1(vector<int>& nums, int target) {
		vector<int> res(2, -1);
		for (int i=0; i < nums.size(); ++i) {
			if (nums[i] == target) {
				res[0] = i;
				int j;
				for (j=i+1; j<nums.size(); ++j) {
					if (nums[j] != target)
						break;
				}

				res[1] = j-1;
				break;
			}
		}
		return res;
	}
	// O(log(n))
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res(2, -1);
		int lo = 0, hi = nums.size()-1;
		while (lo < hi) {
			int mi = lo + (hi-lo)/2;
			if (nums[mi] < target) lo = mi + 1;
			else hi = mi; // nums[mi]>=target
		}
		if (nums[lo] != target) return res; // not found
		res[0] = lo; // must be left start, aka. lower-bound
		hi = nums.size()-1;
		while (lo < hi) {
			int mi = lo + (hi-lo)/2 + 1; // bias to the right
			if (nums[mi] > target) hi = mi - 1; // shrink right half
			else lo = mi;
		}
		res[1] = hi;			// upper-bound - 1
		return res;
	}
};

int main() {
	int arr1[] = {5, 7, 7, 8, 8, 8, 10};
	vector<int> v1(arr1, arr1+7);
	vector<int> res;
	Solution s;
	res = s.searchRange3(v1, 8);
	for (auto x: res)
		cout << x << " ";
	cout << endl;
	res = s.searchRange4(v1, 8);
	for (auto x: res)
		cout << x << " ";
	cout << endl;
}
