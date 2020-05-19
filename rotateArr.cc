/*https://leetcode.com/problems/rotate-array/description/
Given an array, rotate the array to the right by k steps, where k is non-negative.
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	// O(n)
	void rotate(vector<int>& nums, int k) {
		std::rotate(nums.begin(), nums.end()-(k % nums.size()), nums.end());
	}
	void rotate1(vector<int>& nums, int k) {
		int start = 0, n = nums.size();
		for (; k %= n; n -= k, start += k)
			for (int i = 0; i < k; i++) 
				swap(nums[start + i], nums[start + n - k + i]);
	}
	// O(n) time, O(1) space
	void rotate2(vector<int>& nums, int k) {
		// Note: reverse() does not include the last
		int n=nums.size();
		std::reverse(nums.begin(), nums.end());
		std::reverse(nums.begin(), nums.begin()+(k % n));
		std::reverse(nums.begin()+(k % n), nums.end());
	}
	void rotate3(vector<int>& nums, int k) {
		int n=nums.size();
		vector<int> old(nums);		// copy
		for (int i=0; i<n; ++i)
			nums[(i+k)%n] = old[i];	// shift/rotate i+k%n
	}
	void test3(vector<int>& nums, int k) {
		int n=nums.size();
		vector<int> old=nums; // copy
		for (int i=0; i<n; ++i)
			nums[(i+k)%n] = old[i];
	}
	// poor performance (kn^2)
	void rotate4(vector<int>& nums, int k) {
		while (k--) {
			//nums.insert(nums.begin(), nums[nums.size()-1]);
			nums.insert(nums.begin(), nums.end()[-1]);
			nums.pop_back();
		}
	}
};
int main(){
	Solution s;
	vector<int> nums{1,2,3,4,5,6,7};
	vector<int> cp1(nums);
	s.rotate(cp1, 3);
	for (auto x: cp1) cout << x << " ";
	cout << endl;
	vector<int> cp2(nums);
	s.rotate2(cp2, 3);
	for (auto x: cp2) cout << x << " ";
	cout << endl;
	vector<int> cp3(nums);
	s.rotate3(cp3, 3);
	for (auto x: cp3) cout << x << " ";
	cout << endl;
	vector<int> cp4(nums);
	s.rotate3(cp4, 3);
	for (auto x: cp4) cout << x << " ";
	cout << endl;
}
