#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int partitionDisjoint1(vector<int>& A) {
		int localMax = A[0], partitionIdx = 0, gMax = localMax;
		for (int i=1; i< A.size(); ++i) {
			if (localMax > A[i]) {
				localMax = gMax;
				partitionIdx = i;
			} else gMax = max(gMax, A[i]);
		}
		return partitionIdx + 1;
	}
	int partitionDisjoint(vector<int>& A) {
		int n=A.size(), maxL=A[0];
		for (int i=0; i<n-1; ++i) {
			bool flag = true;
			maxL=max(maxL, A[i]);
			for (int j=i+1; j<n; ++j) {
				if (A[j] < maxL) {
					flag = false;
					break;
				}
			}
			if (flag) return i+1;
		}
		assert(0);
	}
};
int main(){
	Solution s;
	vector<int> A1{5,0,3,8,6};
	cout << s.partitionDisjoint1(A1) << endl;
	vector<int> A2{1,1,1,0,6,12};
	cout << s.partitionDisjoint1(A2) << endl;
	vector<int> A3(100000000, 1); A3[100000000-1]=2;
	cout << s.partitionDisjoint1(A3) << endl;
}
