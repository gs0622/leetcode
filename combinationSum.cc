/* https://leetcode.com/problems/combination-sum/description/
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

https://leetcode.com/problems/combination-sum-ii/description/

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution3 {   
public: // backtracing
    vector<vector<int>> combinationSum(vector<int>& C, int target) {
        int n=C.size();
        vector<vector<int>> res;
        vector<int> ans;
        function<void(int,int)> helper=[&](int i, int T){ // i: index, T: recursive target sum
            if (T<0) return;
            else if (T==0) {
                res.push_back(ans);
                return;
            }
            for (int j=i;j<n;++j) {
                ans.push_back(C[j]);
                helper(j,T-C[j]);
                ans.pop_back();
            }
        };
        helper(0,target);
        return res;
    }
};
class Solution2 {
public:
	vector<vector<int>> combinationSum2(vi& C, int T) {
		vvi res;
		vi lst;
		int n = C.size();
		sort(C.begin(),C.end());
		function<void(int,int)> helper=[&](int t, int s) {
			if (t == 0) {
				res.push_back(lst);
				return;
			} else if (t < 0 || s>=n)
				return;
			for (int i=s; i<n; ++i) {
				if (i>s && C[i]==C[i-1])	// tricky: skip dup, (i==s&&C[i]==C[i-1]), require sorted arr to work
					continue;
				lst.push_back(C[i]);
				helper(t-C[i], i+1);		// note: use once
				lst.pop_back();
			}
		};
		helper(T, 0);
		return res;
	}
};
class Solution {
	void backtrack(vector<int>& candidates, int target, vector<vector<int>>& ret, vector<int>& list, int begin) {
		if (target == 0) {
			ret.push_back(list);
			return;
		} else if (target < 0)
			return;
		for (int i = begin; i < candidates.size(); ++i) {
			int v = candidates[i];
			list.push_back(v);
			backtrack(candidates, target-v, ret, list, i);
			list.pop_back();
		}
		return;
	}
public:
	vvi combinationSum2(vi& C, int T) {
		vvi res;
		vi ans;
		function<void(int,int)> helper = [&](int T, int S){
			if (T<0) return;
			else if (T==0) {
				res.push_back(ans);
				return;
			}
			for (int i=S; i<C.size(); ++i) {// enumerate all possible combinations
				ans.push_back(C[i]);
				helper(T-C[i], i);	// not i+1 because elem could be reused
				ans.pop_back();
			}
		};
		helper(T,0);
		return res;
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> ret;
		vector<int> list;
		std::sort(candidates.begin(), candidates.end());
		backtrack(candidates, target, ret, list, 0);
		return ret;
	}
};
int main(){
	vector<int> set {2, 3, 6, 7};
	Solution3 s;
	vector<vector<int>> ret;
	ret = s.combinationSum(set, 7);
	for (auto list: ret) {
		for (auto v: list) {
			cout << v << " ";
		}
		cout << endl;
	}
	cout << endl;
	Solution2 s2;
	vi A1{10,1,2,7,6,1,5};
	for (auto x: s2.combinationSum2(A1,8)) {
		for (auto y: x) cout << y << " ";
		cout << endl;
	}
}
