#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
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
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
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
	Solution s;
	vector<vector<int>> ret;
	ret = s.combinationSum2(set, 7);
	for (auto list: ret) {
		for (auto v: list) {
			cout << v << " ";
		}
		cout << endl;
	}
}
