/*https://leetcode.com/problems/majority-element/description/*/
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
	/*Boyer-Moore Majority Vote Algorithm*/
	int majorityElement(vector<int>& nums) {
		int cnt=1, maj=nums[0];
		for (int i=1; i<nums.size(); ++i) {
			if (cnt==0) {
				cnt++, maj=nums[i];
			} else if (maj==nums[i])
				cnt++;
			else
				cnt--;
		}
		return maj;
	}
	int majorityElement2(vector<int>& nums) {
		unordered_map<int,int> m;
		for (auto n: nums) m[n]++;
		int ans=0, cnt=0;
		for (auto p: m) {
			if (p.second > cnt) {
				cnt = p.second;
				ans = p.first;
			}
		}
		return ans;
	}
};
int main(){
	Solution s;
	vector<int> nums{2,1,1,1,2,3};
	cout << s.majorityElement(nums) << " " << s.majorityElement2(nums) << endl;
}
