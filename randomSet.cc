#include <bits/stdc++.h>
using namespace std;
/* hashmap + vector to archive average O(1)
*/
class RandomizedSet {
	unordered_map<int,int> mp;
	vector<int> nums;
public:
        RandomizedSet() {
		srand(time(0));
        }
	bool insert(int v) {
		if (mp.count(v)>0) return false;
		nums.push_back(v);
		mp[v]=nums.size()-1;	// val as key, index as value
		return true;
	}
	bool remove(int v) {
		if (mp.count(v)==0) return false;
		nums[mp[v]] = nums.back();	// move last to location of v
		mp[nums.back()]=mp[v];		// update index of v
		mp.erase(v);
		nums.pop_back();
		return true;
	}
	int getRandom() {
		return nums[rand()%nums.size()];
	}
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
int main(){}
