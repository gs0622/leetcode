#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int maxP(vector<int>& nums) {
		int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN;
		int min1=INT_MAX,min2=INT_MAX;
		for (auto x: nums) {
			if (x>max1) max1=x;
			else if (x<=max1 && x>max2) max2=x;
			else if (x<=max2 && x>max3) max3=x;
			if (x<min1) min1=x;
			else if (x>=min1 && x<min2) min2=x;
		}
		return std::max(max1*max2*max3, max1*min1*min2);
		
	}
	int maxP2(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		int a=0, b=nums.size()-1;
		return std::max(nums[b]*nums[b-1]*nums[b-2], nums[a]*nums[a+1]*nums[b]);
	}
	int maxP3(vector<int>& nums) {
		int i, j, k, prod, ans=INT_MIN;
		for (i=2; i<nums.size(); ++i) {
			for (j=i-1; j>=1; --j) {
				for (k=j-1; k>=0; --k) {
					prod = nums[i]*nums[j]*nums[k];
					ans = std::max(ans, prod);
				}
			}
		}
		return ans;
	}
};
int main(){
	Solution s;
	vector<int> nums{1,2,3,4};
	cout << s.maxP(nums) << " " << s.maxP2(nums) << endl;
};
