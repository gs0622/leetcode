#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> r;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (target == nums[i] + nums[j]) {
                    r.push_back(i), r.push_back(j);
                }
            }
        }
        return r;
    }
    vector<int> twoSum_v2(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> r;
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]] = i;
        for (int i = 0; i < nums.size(); i++) {
            int v = target - nums[i];
            if (m.find(v) != m.end() && m[v] != i) {
                r.push_back(i);
                r.push_back(m[v]);
                return r;
            }
        }
    }
};

int main() {
    int a[] = {3,2,4};
    vector<int> nums(a, a+3);
    Solution s;
    vector<int> r = s.twoSum_v2(nums, 6);
    for (auto x: r)
        cout << x << " ";
    cout << endl;
    return 0;
}

