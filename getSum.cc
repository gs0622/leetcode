#include <iostream>
using namespace std;
class Solution {
public:
	int getSum(int a, int b) {
		int sum = a;
		while (b != 0) {
			sum = a^b;	// sum w/o carry
			b = (a&b) << 1;	// w/ carry
			a = sum;
		}
		return sum;
	}
	int getSum2(int a, int b) {
		if (b == 0) return a;
		int sum = a^b, carry = (a&b)<<1;
		return getSum(sum, carry);
	}
};
int main(){
	Solution s;
	cout << "1+2=" << s.getSum(1,2) << endl;
	cout << "1+3=" << s.getSum(1,3) << endl;
}
