/* https://leetcode.com/problems/can-place-flowers/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool canPlaceFlowers(vector<int>& f, int n) {
		int i, cnt, prev, next;
		for (i=0, cnt=0; i<f.size();) {
			if (f[i]==1) i+=2;
			else {
				prev = (i==0)? 0: f[i-1];
				next = (i==f.size()-1)? 0: f[i+1];
				if (prev == 0 && next == 0) {
					if (++cnt == n) return true;
					i+=2;
				} else i++;
			}
		}
		return false;
	}
	bool canPlaceFlowers2(vector<int>& f, int n) {
		int i, cnt, prev, next;
		for (i=0, cnt=0; i<f.size() && cnt<n; ++i) {
			if (f[i]==0) {
				prev = (i==0)? 0: f[i-1];
				next = (i==f.size()-1)? 0: f[i+1];
				if (prev == 0 && next == 0)
					f[i]=1, cnt++;
			}
		}
		return cnt==n;
	}
};
int main(){
	Solution s;
	vector<int> nums1{1,0,0,0,1};
	vector<int> nums2{1,0,0,0,1};
	cout << s.canPlaceFlowers(nums1, 1) << endl;
	cout << s.canPlaceFlowers(nums2, 2) << endl;
}
