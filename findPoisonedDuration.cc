#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// beautiful one
	int findPoisonedDuration1(vector<int>& T, int D) {
		int res=D*T.size();
		for (int i=1; i<T.size(); ++i)
			res-=max(0, D-(T[i]-T[i-1]));
		return res;
	}
	int findPoisonedDuration(vector<int>& T, int D) {
		int res=0, cap=INT_MAX;
		for (int i=T.size()-1; i>=0; --i) {
			int top=T[i];
			res+=(top+D)<=cap? D: cap-top;
			cap=top;
		}	
		return res;
	}
};
int main(){
	Solution s;
	vector<int> nums1{1,4,5};
	vector<int> nums2{1,2};
	cout << s.findPoisonedDuration(nums1, 2) << ' ' << s.findPoisonedDuration1(nums1, 2) << endl;
	cout << s.findPoisonedDuration(nums2, 2) << ' ' << s.findPoisonedDuration1(nums2, 2) << endl;
}
