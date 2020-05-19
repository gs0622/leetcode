class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::set<int> myset;
        for (int i = 0; i < nums.size(); i++) {
                if (i > k) myset.erase(nums[i-k-1]);	// maintain the k window
                if (!myset.insert(nums[i]).second)
                        return true;
        }   
        return false;
    }
};
