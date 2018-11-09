#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int integerBreak(int n) {
		if (n==2 || n==3) return n-1;
		int prod = 1;
		while (n>4) {
			prod*=3;
			n-=3;
		}
		prod*=n; // left, and the corner case of 4
		return prod;
	}
};
int main(){
	Solution s;
	cout << s.integerBreak(10) << endl;
	cout << s.integerBreak(20) << endl;
	cout << s.integerBreak(3) << endl;
	cout << s.integerBreak(5) << endl;
}
