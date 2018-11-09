#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// O(n^2) two-pointer
	vector<vector<int>> threeSum2(vector<int>& nums) {
		int i,n=nums.size();
		vector<vector<int>> res;
		sort(begin(nums), end(nums));
		for (i=0; i<n-2; ++i) {
			if (i==0 || (i>0 && nums[i]!=nums[i-1])) {
				int lo=i+1, hi=n-1;	// reduce to two sum
				while (lo<hi) {
					if (nums[i]+nums[lo]+nums[hi]==0) {
						res.push_back({nums[i], nums[lo], nums[hi]});
						while (lo<hi && nums[lo]==nums[lo+1]) ++lo;
						while (lo<hi && nums[hi]==nums[hi-1]) --hi;
						++lo, --hi;
					} else if (nums[i]+nums[lo]+nums[hi]<0) ++lo;
					else --hi;
				}
			}
		}
		return res;
	}
	// Brute-force
	vector<vector<int>> threeSum1(vector<int>& nums) {
		int i,j,k,n=nums.size();
		sort(begin(nums), end(nums));
		/*nums.resize(distance(begin(nums), unique(begin(nums), end(nums))));
		n=nums.size();*/ // wrong, this will cut cases like [-1,-1,2]
		set<pair<pair<int,int>,int>> set;
		for (i=0; i<n; ++i) {			// O(n^3)
			for (j=i+1; j<n; ++j) {
				for (k=j+1; k<n; ++k) {
					if (nums[i]+nums[j]+nums[k] == 0) {
						// if there is dup numbers, it would generate dup combination, use set to eliminate it
						//cout << nums[i] << ' ' << nums[j] << ' ' << nums[k] << endl;
						set.insert(make_pair(make_pair(nums[i], nums[j]), nums[k]));
					}
				}
			}
		}
		vector<vector<int>> res;
		for_each(begin(set), end(set), [&res](pair<pair<int,int>,int> s){
			res.push_back({s.first.first, s.first.second, s.second});
		});
		return res;
	}
	vector<vector<int>> threeSum(vector<int>& nums) {
		std::unordered_map<int, int> m, n;
		std::vector<int> striped;
		std::set<vector<int> > s;
		std::sort(nums.begin(), nums.end());
		int i, j, sz = nums.size();

		// stripe duplicated nums, expecially for bunch of '0'
		for (i = 0, j = 0; i < sz; ++i) {
			++m[nums[i]];
			if (m[nums[i]] < 4) {
				striped.push_back(nums[i]);
				n[nums[i]] = j++;
			}
		}
		sz = striped.size();

		for (i = 0; i < sz - 1; i++) {
			for (j = i+1; j < sz; j++) {
				int sum = striped[i] + striped[j];
				auto it = n.find(-sum);
				if (it != n.end()) {
					int idx = it->second;
					if (idx == i || idx == j) continue;
					vector<int> triple;
					triple.push_back(striped[i]);
					triple.push_back(striped[j]);
					triple.push_back(it->first);
					std::sort(triple.begin(), triple.end());
					s.insert(triple);
				}
			}
		}
		vector<vector<int> > v;
		for (auto t: s) v.push_back(t);
		return v;
	}
};

int main(void)
{
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    //vector<int> nums(3000, 0);
    Solution s;
    vector<vector<int> > r = s.threeSum1(nums);
    for (auto x: r) {
        for (auto y: x)
            //cout << y << " ";
        cout << endl;
    }
    return 0;
}

