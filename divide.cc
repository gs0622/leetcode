#include <climits>
#include <cstdlib>
#include <iostream>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        int ans = 0;
	if (divisor == 0) return INT_MAX;
	if (divisor == 1 && dividend == INT_MAX) return INT_MAX;
	if (divisor == -1 && dividend == INT_MAX) return INT_MIN;
	if (divisor == 1 && dividend == INT_MIN) return INT_MIN;
	if (divisor == -1 && dividend == INT_MIN) return INT_MAX;
	int sign = ((dividend > 0) ^ (divisor > 0))? -1: 1;
	long long numerator = labs(dividend);
	long long demominator = labs(divisor);
	while (numerator >= demominator) {
		long long tmp = demominator, mul = 1;
		while (numerator >= (tmp<<1)) {
			tmp <<= 1, mul <<= 1;
		}
		numerator -= tmp;
		ans += mul;
	}
	return (sign == 1)? ans: -ans;
    }
};
int main() {
	Solution s;
	cout << s.divide(-2147483648, 1) << endl;
	cout << s.divide(1, 1) << endl;
	cout << s.divide(5, 2) << endl;
	cout << s.divide(7, -2) << endl;
}
