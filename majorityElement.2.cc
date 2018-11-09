/*
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// Boyer-Moore majority vote
	vector<int> majorityElement1(vector<int>& nums) {
		// pass 1: find candidate; cnt=0, maj=any
		int cnt1=0, cnt2=0, maj1=0, maj2=1;
		for (auto n: nums) {
			if (n==maj1) cnt1+=1;
			else if (n==maj2) cnt2+=1;
			else if (cnt1==0) maj1=n, cnt1=1;
			else if (cnt2==0) maj2=n, cnt2=1;
			else cnt1-=1, cnt2-=1; 
		}
		// pass 2: verify majority elems
		cnt1 = cnt2 = 0;
		for (auto n: nums) {
			if (n==maj1) cnt1++;
			else if (n==maj2) cnt2++;
		}
		vector<int> res;
		auto n=nums.size();
		if (cnt1>(n/3)) res.push_back(maj1);
		if (cnt2>(n/3)) res.push_back(maj2);
		return res;
	}
	vector<int> majorityElement(vector<int>& nums) {
		unordered_map<int,int> m;
		int n=nums.size();
		vector<int> res;
		for (auto x: nums) ++m[x];
		for (auto x: m) if (x.second > n/3) res.push_back(x.first);
		return res;
	}
};
int main(){
	Solution s;
	vector<int> res;
	vector<int> nums{1,1,1,1,2,2,2,3,3,3,3};
	res = s.majorityElement(nums);
	for (auto x: res) cout << x << " ";
	cout << endl;
	res = s.majorityElement1(nums);
	for (auto x: res) cout << x << " ";
	cout << endl;
}
