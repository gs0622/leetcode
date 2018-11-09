/* non-duplicate/dup twosum design */
#include<bits/stdc++.h>
using namespace std;
class Solution {
	unordered_set<int> nums;
public:
	// O(log(n)) time of BST-like hashtable, O(n) space
	void add(int n) {
		nums.insert(n);
	}
	// O(n) hashtable search time
	bool find(int target) {
		for (auto n: nums)
			if (nums.count(target-n) && (n != target - n)) // tricky: check itself
				return true;
		return false;
	}
};
class Solution2 {
	unordered_map<int,int> nums;
public:
	void add(int n) { ++nums[n]; }
	bool find(int target) {
		for (auto n: nums) {
			auto it = nums.find(target-n.first);
			if (it != nums.end()) {
				if (it->first != n.first || it->second > 1) {
					//cout << it->first << " + " << n.first << endl;
					return true;
				}
			}
		}
		return false;
	}
};
class Solution3 {
	// Q: possible overflow in sum?
	// Q: what about adding dup num?
	// O(n^2) space, O(n) add, O(1) find
	unordered_map<int, vector<pair<int,int>>> map;
	vector<int> nums;
public:
	void add(int n) {
		if (nums.size() > 1) {
			for (auto i: nums)
				map[i+n].push_back(make_pair(i, n));
		}
		nums.push_back(n);
	}
	bool find(int target) {
		return (map.find(target) != map.end());
	}
};
int main(){
	Solution3 s;
	s.add(1), s.add(3), s.add(5);
	s.add(5);
	cout << s.find(4) << endl;	// true
	cout << s.find(7) << endl;	// false
	cout << s.find(10) << endl;	// false
	cout << s.find(11) << endl;	// false
}
