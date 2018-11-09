#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <stdio.h>

using namespace std;
struct triple { int x, y, z;};

class Solution {
private:
    vector<vector<int>> threeSum(vector<int>& nums, int target, int first, vector<vector<int> >& v) {
        std::unordered_map<int, int> m;
        std::set<vector<int> > s;
        int i, j, sz = nums.size();
        // stripe duplicated nums, expecially for bunch of '0'
        for (i = 0; i < sz; i++) m[nums[i]] = i;
        for (i = 0; i < sz - 1; i++) {
            if (i == first) continue;
            for (j = i+1; j < sz; j++) {
                if (j == first) continue;
                int sum = nums[i] + nums[j];
                auto it = m.find(target - sum);
                if (it != m.end()) {
                    int idx = it->second;
                    if (idx == i || idx == j || idx == first) continue;
                    vector<int> quadruplets;
                    quadruplets.push_back(nums[first]);
                    quadruplets.push_back(nums[i]);
                    quadruplets.push_back(nums[j]);
                    quadruplets.push_back(it->first);
                    std::sort(quadruplets.begin(), quadruplets.end());
                    s.insert(quadruplets);
                }
            }
        }
        for (auto t: s) v.push_back(t);
        return v;
    }
public:
	vector<vector<int>> fourSum1(vector<int>& nums, int target) {
		vector<vector<int>> res;
		int i, j, k, n=nums.size();
		sort(begin(nums), end(nums));
		for (i=0; i<n; ++i) {
			for (j=i+1; j<n; ++j) {
				int target2 = target-nums[i]-nums[j];			// reduce to two sum
				int lo=j+1, hi=n-1;
				while (lo<hi) {
					int sum = nums[lo]+nums[hi];
					if (sum < target2) ++lo;
					else if (sum > target2) --hi;
					else {
						int a = nums[lo], b = nums[hi];
						res.push_back({nums[i], nums[j], a, b});
						while (lo<hi && nums[lo]==a) ++lo;	// tricky: deal w/ dup keys
						while (lo<hi && nums[hi]==b) --hi;
					}
				}
				while (j+1<n && nums[j+1]==nums[j]) ++j;		// dual w/ dup keys
			}
			while (i+1<n && nums[i+1]==nums[i]) ++i;			// dual w/ dup keys
		}
		return res;
	}
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> m;
        std::sort(nums.begin(), nums.end());
        int i, j, sz = nums.size();
        vector<vector<int> > v;
        vector<int> striped;

        for (i = 0; i < sz; i++) {
            if (m[nums[i]] < 5)
                striped.push_back(nums[i]);
        }
        sz = striped.size();

        for (i = 0; i < sz; i++) {
            int target2 = target - striped[i];
            threeSum(striped, target2, i, v);
        }

        std::set<vector<int>> s;
        sz = v.size();
        for (i = 0; i < sz; i++) {
            vector<int> v2 = v[i];
            std::sort(v2.begin(), v2.end());
            if (s.find(v2) == s.end())
                s.insert(v2);
        }
        vector<vector<int> > v2;
        for (auto x: s) v2.push_back(x);
        return v2;
    }
};

int main(void)
{
	//vector<int> v{1, 0, -1, 0, -2, 2};
	//vector<int> v{-3,-2,-1,0,0,1,2,3};
	vector<int> v{-1,-5,-5,-3,2,5,0,4};
	//vector<int> v(3000, 0);
	Solution s;
	vector<vector<int>> r;
	r = s.fourSum(v, 0);
	for (auto x: r) {
		for (auto y: x) cout << y << " ";
		cout << endl;
	}
	cout << endl;
	r = s.fourSum1(v, 0);
	for (auto x: r) {
		for (auto y: x) cout << y << " ";
		cout << endl;
	}
	return 0;
}

