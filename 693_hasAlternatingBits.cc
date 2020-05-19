#include <iostream>
using namespace std;
class Solution {
public:
	bool hasAlternatingBits1(int n) {
		int lsb=n&1;
		while (n&1 == lsb} {
			lsb=1-lsb;	// flip
			n>>=1;
		}
		return n==0;		// all bits are passed 
	}
	bool hasAlternatingBits(int n) {
		//n ^= n>>1;
		//n &= (n-1);
		//return n!=0;
		return !((n ^= n/2) & n+1);
/*
    000101010
  ^ 000010101
  = 000111111

n+1 triggers carry then & op would make it become 0
*/
    }
};
int main(){
	Solution s;
	cout << s.hasAlternatingBits(5) << endl;
	cout << s.hasAlternatingBits(7) << endl;
	cout << s.hasAlternatingBits(11) << endl;
	cout << s.hasAlternatingBits(10) << endl;
}
