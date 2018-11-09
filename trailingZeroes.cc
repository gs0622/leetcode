/* https://leetcode.com/problems/factorial-trailing-zeroes/description/
 # Math
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int trailingZeroes(int n) {
		int c=0;
		while (n/5) {
			c+=n/5;
			n/=5;
		}
		return c;
	}
	// wrong
	int trailingZeroes1(int n) {
		long long i;
		int c=0;
		for (i=5; i<=n; i+=5) c+=1;
		return c;
	}
	// correct
	int trailingZeroes2(int n) {
		long long i;
		int c=0;
		for (i=5; n/i>0; i*=5) c+=n/i;
		return c;
	}
};
int main(){
	Solution s;
	cout << s.trailingZeroes(25) << " " << s.trailingZeroes2(25) <<  endl;
	cout << s.trailingZeroes(1808548329) << " "  << s.trailingZeroes2(1808548329) << endl;
}
