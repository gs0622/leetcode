#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isPalidrome1(int n) {
		if (n<0 || (n!=0 && n%10==0)) return false;	// 0 is counted
		int rev=0;
		while (n>rev)
			rev=rev*10+n%10, n/=10;
		return n==rev || n == rev/10;
	}
	bool isPalidrome(int n) {
		if (n<0) return false;
		int div=1;
		while (div*10<=n) div*=10;		// alternate: while (n/div>=10) div*=10;
		while (n!=0) {
			if (n/div!=n%10) return false;	// compare MSB/LSB two digits
			n=(n%div)/10;			// strip MSB/LSB two digits
			div/=100;
		}
		return true;
	}
};
int main(){
	Solution s;
	cout << s.isPalidrome1(-123) << endl;
	cout << s.isPalidrome(23432) << endl;
	cout << s.isPalidrome(2332) << endl;
}
