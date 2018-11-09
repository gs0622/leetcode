#include <iostream>
using namespace std;
class Solution {
public:
    bool hasAlternatingBits(int n) {
	//n ^= n>>1;
	//n &= (n-1);
	//return n!=0;
	return !((n ^= n/2) & n+1);
    }
};
int main(){
	Solution s;
	cout << s.hasAlternatingBits(5) << endl;
	cout << s.hasAlternatingBits(7) << endl;
	cout << s.hasAlternatingBits(11) << endl;
	cout << s.hasAlternatingBits(10) << endl;
}
