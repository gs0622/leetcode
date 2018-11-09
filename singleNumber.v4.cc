#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res=0;
		for (auto n: nums)
			res ^= n;
		return res;
	}
	int singleNumber1(vector<int>& nums) {
		int ans1, ans2;
		do {
			unordered_map<int,int> maps;
			for (auto x: nums) maps[x]+=1;
			for (auto y: maps)
				if (y.second == 1) ans1 = y.first;
		} while (0);
		do {
			int x = 0;
			for (auto y: nums) x ^= y;
			ans2 = x;
		} while (0);
		cout << ans1 << " " << ans2 << endl;
		assert(ans1==ans2);
		return ans1;
	}
};
int main(){
	Solution s;
	vector<int> nums{1,1,2,3,3,4,4,5,5};
	srand(time(0));
	random_shuffle(begin(nums), end(nums));
	copy(begin(nums), end(nums), ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << s.singleNumber(nums) << endl;
}
