#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		int n=bits.size(), i=0;
		while (i<n-1) {
			if (bits[i]==0) ++i;	// one-bit char
			else i+=2;		// two-bit char
		}
		return i==n-1;
	}
};
int main(){
	Solution s;
	vector<int> A1{1,1,0};
	cout << s.isOneBitCharacter(A1) << endl; 
	vector<int> A2{1,1,1,0};
	cout << s.isOneBitCharacter(A2) << endl; 
}
