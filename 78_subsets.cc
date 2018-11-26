/* https://leetcode.com/problems/subsets/description/
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.
*/
#include <algorithm>
/* https://leetcode.com/problems/subsets/description/
#recursive
#iterative
#bit-manipulation
*/
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
/*
To give all the possible subsets, we just need to exhaust all the possible combinations of the numbers.
And each number has only two possibilities: either in or not in a subset. And this can be represented using a bit.

Using [1, 2, 3] as an example, 1 appears once in every two consecutive subsets, 2 appears twice in every four consecutive subsets, and 3 appears four times in every eight subsets (initially all subsets are empty):
[], [], [], [], [], [], [], []
[], [1], [], [1], [], [1], [], [1]
[], [1], [2], [1, 2], [], [1], [2], [1, 2]
[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]
*/
class Solution3 {
public:
	vvi subsets(vi& nums) {
		int n=nums.size(), m=1<<n;
		vvi res(m, vi());
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				if ((j>>i) & 1)		// taken, empty for not-taken
					res[j].push_back(nums[i]);
			}
		}
		return res;
	}
};
/*
While iterating through all numbers, for each new number, we can either pick it or not pick it
1, if pick, just add current number to every existing subset.
2, if not pick, just leave all existing subsets as they are.
We just combine both into our result.
*/
class Solution2 {	// recursive
public:
	// backtracking
	vvi subsets(vi& nums) {
		vvi res;
		vi sub;
		int n=nums.size();
		function<void(int)> helper=[&](int i) {
			res.push_back(sub);
			for (int j=i; j<n; ++j) {
				sub.push_back(nums[j]);	// res.back().push_back()
				helper(j+1);
				sub.pop_back();
			}
		};
		helper(0);
		return res;
	}
};
class Solution {	// iterative
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int i, j, n, m=nums.size();
		vector<vector<int>> res(1, vector<int>());	// empty one
		for (i=0; i<m; ++i) {
			n=res.size();	// n=1, 2, 4, ...etc
			for (j=0; j<n; ++j) {
				res.push_back(res[j]);		// clone all previous subset
				res.back().push_back(nums[i]);	// pick this num into subset
			}
		}
		return res;
	}
};
int main(){
	Solution3 s;
	vector<int> nums{1,2,3};
	vector<vector<int>> res = s.subsets(nums);
	for (auto a: res) {
		for (auto b: a) cout << b << " ";
		cout << endl;
	}
}
