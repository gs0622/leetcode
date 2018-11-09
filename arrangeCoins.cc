#include <iostream>
using namespace std;
class Solution {
public:
	int arrangeCoins(int n) {
		int i=1;
		while (n>=i) n-=i, ++i;
		return i-1;
	}
	int arrangeCoins2(int n) {
		int i;
		for (i=1;; ++i)
			if ((i*(i+1)/2) > n) break;
		return i-1;
	}
};
int main(){
	Solution s;
	cout << s.arrangeCoins(5) << ": ";
	cout << s.arrangeCoins2(5) << endl;
	cout << s.arrangeCoins(8) << ": ";
	cout << s.arrangeCoins2(8) << endl;
	cout << s.arrangeCoins(1) << ": ";
	cout << s.arrangeCoins2(1) << endl;
}

