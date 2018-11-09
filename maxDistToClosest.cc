#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	//	 1  0  0  0  0  1  0  1
	//  res  0  -  -  -  -  2  -  2
	//    d  1  2  3  4  5  1  2  1
	//
	//       1  0  0  0
	//  res  0  -  -  -
	//    d  1  2  3  4
	//
	//       0  0  0  1
	//  res -1  -  -  3
	//    d  1  2  3  1
	int maxDistToClosest(vector<int>& seats) {
		int res=-1,d=0;
		for (auto n: seats) {
			if (n) {
				if (res==-1) res=d;
				else res=max(res,d/2);
				d=1;
			} else ++d;
		}
		return max(res,d-1);
	}
};
int main(){
	Solution s;
	vector<int> nums1{1,0,0,0,1,0,1};
	vector<int> nums2{1,0,0,0};
	vector<int> nums3{0,0,0,1};
	cout << s.maxDistToClosest(nums1) << endl;
	cout << s.maxDistToClosest(nums2) << endl;
	cout << s.maxDistToClosest(nums3) << endl;
}
