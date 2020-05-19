/* https://leetcode.com/problems/powx-n/description/
*/
#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (n==0) return 1;
		if (n==INT_MIN) return myPow(1/x, INT_MAX) / x;	// coner case of overflow
		if (n<0) n=-n, x=1/x;
		return (n%2==0)? myPow(x*x, n/2): x*myPow(x*x, n/2);  // even and odd
	}
	double myPow1(double x, int n) {
		if (n==0) return 1;
		//if (n==1) return x;
		if (n==INT_MIN) return myPow(1/x, INT_MAX) / x;
		if (n<0) return myPow(1/x, -n);
		if (n%2 == 0) return myPow(x*x, n/2);
		else return x*myPow(x*x, n/2);
	}
    double myPow2(double x, int n) {
        double r = 1;
        while (n--)
            r *= x;
        return r;       
    }
};

int main() {
    Solution s;
    cout << s.myPow(2.0, 10) << endl;
    cout << s.myPow(0.2, 10) << endl;
    cout << s.myPow(0.5,2147483647) << endl;
    cout << s.myPow(-0.5,-2147483648) << endl;
    cout << s.myPow(2,-2147483648) << endl;
    cout << s.myPow(0.5,2147483648) << endl;
    cout << s.myPow(0,0) << endl;
    return 0;
}
