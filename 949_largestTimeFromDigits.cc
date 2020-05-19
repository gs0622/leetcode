#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string largestTimeFromDigits(vector<int>& A) {
		sort(A.begin(), A.end());
		string res;
		do {
			if ((A[0]<2 || (A[0]==2 && A[1]<4)) && A[2]<6 && A[3]<=9)
				res = max(res, to_string(A[0])+to_string(A[1])+":"+to_string(A[2])+to_string(A[3]));
		} while (next_permutation(A.begin(), A.end()));
		return res;
	}
};
int main(){
	Solution s;
	vector<int> A1{1,2,3,4};
	cout << s.largestTimeFromDigits(A1) << endl;
}
