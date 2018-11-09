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
private:
    long getID(long i, long w) {
        return i < 0 ? (i + 1) / w - 1 : i / w;
    }
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0) return false;
        map<long, long> mymap;
        long w = (long) t + 1;
        for (int i = 0; i < nums.size(); i++) {
            long m = getID(nums[i], w);
            if (mymap.count(m) > 0) return true;
            if (mymap.count(m-1) > 0 && abs(nums[i] - mymap.find(m-1)->second) < w) return true;
            if (mymap.count(m+1) > 0 && abs(nums[i] - mymap.find(m+1)->second) < w) return true;
            mymap.insert(make_pair(m, (long) nums[i]));
            if (i >= k) mymap.erase(getID(nums[i-k], w));
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
