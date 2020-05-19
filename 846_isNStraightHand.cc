#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(nlogn), n is different cards
	bool isNStraightHand(vector<int>& hand, int W) {
		map<int,int> mp;
		for (auto n: hand) ++mp[n];			// 1,2,3,2,3,4 -> 1:1, 2:2, 3:2, 4:1
		for (auto p: mp) {
			int start = p.first;
			if (mp[start] > 0) {
				for (int i=W-1; i>=0; --i) {	// 1:1, 2:2, 3:2: 4:1 -> 1:0, 2:1, 3:1: 4:1
					mp[start+i]-=mp[start];
					if (mp[start+i] < 0)
						return false;
				}
			}
		}
		return true;
	}
};
int main(){
	Solution s;
	vector<int> A1{1,2,3,6,2,3,4,7,8};
	cout << s.isNStraightHand(A1,3) << endl;
}
