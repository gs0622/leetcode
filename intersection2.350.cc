#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um1, um2;
        vector<int> ans;
        if (0 == nums1.size() || 0 == nums2.size()) return ans;
        for (auto x: nums1)
            um1[x]++;
        for (auto y: nums2)
            um2[y]++;

        for (auto z: nums1) {
            if (um2.find(z) != um2.end()) {
                while ((um1[z] > 0) && (um2[z] > 0)) {
                    ans.push_back(z);
                    um1[z]--;
                    um2[z]--;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> n1 = {1, 2, 2, 1};
    vector<int> n2 = {2};
    //vector<int> n1 = {3, 1, 2};
    //vector<int> n2 = {1, 1};
    Solution s;
    vector<int> ans = s.intersect(n1, n2);
    for (auto x: ans)
        cout << x;
    cout << endl;
    return 0;
}

