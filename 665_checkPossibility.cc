#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(n) time
	bool checkPossibility1(vector<int>& nums) {
		int n=nums.size();
		for (int i=0; i<n-1; ++i) {
			if (nums[i]>nums[i+1]) {
				int save=nums[i];
				nums[i]=nums[i+1];	// lower down nums[i]
				if (is_sorted(nums.begin(), nums.end())) return true;
				nums[i]=nums[i+1]=save;	// rise up
				if (is_sorted(nums.begin(), nums.end())) return true;
				return false;
			}
		}
		return true;
	}
	// O(n) time
	bool checkPossibility(vector<int>& nums) {
		int n=nums.size(), cnt=0;
		for (int i=1, prev=nums[0]; i<n; ++i) {
			if (prev > nums[i] && cnt++ > 0) return false;
			if (prev > nums[i] && i>=2 && nums[i-2]>nums[i]) continue;
			prev=nums[i];
		}
		return true;
	}
};
int main(){
	Solution s;
	vector<int> A1{4,2,3};
	cout << s.checkPossibility1(A1) << endl;
	vector<int> A2{4,2,1};
	cout << s.checkPossibility1(A2) << endl;
	vector<int> A3{3,4,2,3};
	cout << s.checkPossibility1(A3) << endl;
}
