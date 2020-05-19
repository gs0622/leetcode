#include <bits/stdc++.h>
using namespace std;
class MapSum {
	map<string,int> mp;	// ordered map inorder to use lower_bound
public:
	/** Initialize your data structure here. */
	MapSum() {
		mp.clear();
	}
	void insert(string key, int val) {
		mp[key]=val;
	}
	int sum(string prefix) {
		int res=0, n=prefix.size();
		for (auto it=mp.lower_bound(prefix);
			it!=mp.end() && it->first.substr(0,n)==prefix;	// ordered map is key data structure
			++it)
			res+=it->second;
		return res;
	}
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
int main(){
}
