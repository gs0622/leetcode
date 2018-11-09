#include <bits/stdc++.h>
using namespace std;
/* hashmap + vector to archive average O(1)
*/
class RandomizedCollection {
	unordered_map<int,set<int>> mp;
	vector<int> nums;
public:
        RandomizedCollection() {
		srand(time(0));
        }
	bool insert(int v) {
		nums.push_back(v);
		mp[v].insert(nums.size()-1);
		return (mp[v].size()<2);
	}
	bool remove(int v) {
		if (mp.count(v)==0) return false;				// not exist
		int id=*mp[v].begin(), mv=nums.size()-1, va=nums.back();	// get remove id, moving id of last, value of last
		mp[v].erase(id);						// remove id
		if (mp[v].empty())
			mp.erase(v);
		if (id!=nums.size()-1)
			nums[id] = va, mp[va].erase(mv), mp[va].insert(id);	// move last to removed id, update index
		nums.pop_back();						// remove value
		return true;
	}
	int getRandom() {
		return nums[rand()%nums.size()];
	}
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
/*
["RandomizedCollection","insert","insert","insert","insert","insert","insert","remove","remove","remove","remove","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"]
[[],[10],[10],[20],[20],[30],[30],[10],[10],[30],[30],[],[],[],[],[],[],[],[],[],[]]
*/
int main(){
	RandomizedCollection R;
	//R.insert(10), R.insert(10), R.insert(20), R.insert(20), R.insert(30), R.insert(30);
	//R.remove(10), R.remove(10), R.remove(30), R.remove(30);
	R.insert(0), R.remove(0), R.insert(-1), R.remove(0);
	cout << R.getRandom() << endl;
	cout << R.getRandom() << endl;
	cout << R.getRandom() << endl;
	cout << R.getRandom() << endl;
	cout << R.getRandom() << endl;
	cout << R.getRandom() << endl;
	cout << R.getRandom() << endl;
	cout << R.getRandom() << endl;
	cout << R.getRandom() << endl;
	cout << R.getRandom() << endl;
}
