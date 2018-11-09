/* twosum data struct design
 tradeoff
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
	vector<int> nums;
	bool isSorted() {
		if (nums.empty()) return false;
		for (int i=1; i<nums.size(); ++i)
			if (nums[i]<nums[i-1])
				return false;
		return true;
	}
public:
	// O(1)
	void add1(int n) { nums.push_back(n); }
	// O(log(n)) time make vector sorted
	void add(int n) {
		auto it = upper_bound(begin(nums), end(nums), n);
		nums.insert(it, n);
	}
	// O(nlog(n))
	bool find(int target) {
		if (nums.empty()) return false;
		//if (!isSorted()) sort(begin(nums), end(nums));
		//else cout << "sorted" << endl;
		for (int i=0, j=nums.size()-1; i<j;) {
			int sum = nums[i]+nums[j];
			if (sum < target) ++i;
			else if (sum > target) --j;
			else return true;
		}
		return false;
	}
	vector<pair<int,int>> findPair(int target) {
		if (nums.empty()) return {};
		//if (!isSorted()) sort(begin(nums), end(nums));
		vector<pair<int,int>> res;
		for (int i=0, j=nums.size()-1; i<j;) {
			int sum = nums[i]+nums[j];
			if (sum < target) ++i;
			else if (sum > target) --j;
			else res.push_back(make_pair(nums[i++], nums[j--]));
		}
		return res;
	}
};
int main(){
	Solution s;
	s.add(1), s.add(5), s.add(3);
	s.add(5), s.add(9);
	cout << s.find(4) << endl;	// true
	cout << s.find(7) << endl;	// false
	cout << s.find(10) << endl;	// true
	vector<pair<int,int>> res = s.findPair(10);
	for (auto x: res) cout << x.first << " " << x.second << endl;

}
