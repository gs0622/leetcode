/*
https://leetcode.com/problems/contains-duplicate-iii

Given an array of integers, find out whether there are two distinct indices i and j in the array
such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
*/
#include <cmath>
#include <climits>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> m;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - j > k) m.erase(nums[j++]);
            auto a = m.lower_bound((long long)nums[i] - t);
            if (a != m.end() && abs(a->first - nums[i]) <= t) return true;
            m[nums[i]] = i;
        }
        return false;
    }
};

int main(void) {
    //int a[] = {2147483647, -2147483647};
    int a[] = {1, 3, 1};
    vector<int> v(a, a+3);
    Solution s;
    cout << s.containsNearbyAlmostDuplicate(v, 1, 1) << endl;
    return 0;
}
