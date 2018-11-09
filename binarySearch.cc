#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int search1(vector<int>& nums, int target) {
		int lo=0, hi=nums.size()-1;
		while (lo<hi) {
			int mi=lo+(hi-lo)/2;
			if (nums[mi]<target) lo=mi+1;	// cut the smaller half
			else hi=mi;
		}
		return nums[lo]==target? lo: -1;
	}
	int search(vector<int>& nums, int target) {
		for (int i=0; i<nums.size(); ++i)
			if (nums[i]==target)
				return i;
		return -1;
	}
};
int main(){
	Solution s;
	vector<int> A{-1,0,3,5,9,12};
	cout << s.search(A, 9) << " " << s.search1(A, 9) << endl;
}
