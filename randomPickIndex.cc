/* https://leetcode.com/problems/random-pick-index/description/
hint: Reservoir Sampling
*/
#include <bits/stdc++.h>
using namespace std;

class Solution2 {
	map<int,vector<int>> mp;
	//vector<int> cnt, val;
public:
	// O(n)
	Solution2(vector<int> nums) {
		//cnt.resize(nums.size());
		for (int i=0; i<nums.size(); ++i) {
			mp[nums[i]].push_back(i);
			//cnt[i]=0;
		}
		//val=std::move(nums);
	}
	// O(log(n))
	int pick(int target) {
		int n=mp[target].size(), r=rand()%n;
		//++cnt[mp[target][r]];
		return mp[target][r];
	}
	//void dump(void) {
	//	for (int i=0; i<val.size(); ++i)
	//		cout << val[i] << ": " << cnt[i] << endl;
	//}
};
class Solution {
	vector<int> nums;
public:
	// O(n)
	Solution(vector<int> nums) { this->nums=std::move(nums); }
	// O(n)
	int pick(int target) {
		int cnt=0;
		for (auto n: nums)
			if (n==target) ++cnt;
		int rnd=rand()%cnt;
		for (int i=0, j=0; i<nums.size(); ++i) {
			if (nums[i]==target) {
				if (j==rnd) return i;
				++j;
			}
		}
		assert(0);
	}
};

int main(){
	srand(time(0));
	vector<int> nums1{1,2,3,3,3,3,3,3,3};
	random_shuffle(begin(nums1), end(nums1));
	for (auto n: nums1) cout << n << ' ';
	cout << endl;
	Solution2 s(nums1);
	for (int i=0; i<1e5; ++i) {
		cout << s.pick(3) << endl;
		//s.pick(3);
	}
	//s.dump();
}
