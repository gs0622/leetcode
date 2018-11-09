#include <bitset>
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
	set<int> s{2, 3, 5, 7, 11, 13, 17, 19, 23};
	int ans = 0;
	for (int i=L; i<=R; ++i) {
		//std::bitset<32> bits(i);
		//ans += s.count(bits.count());
		ans += s.count(__builtin_popcount(i));
	}
	return ans;
    }
};
int main(){
	Solution s;
	cout << s.countPrimeSetBits(6, 10) << endl;
	cout << s.countPrimeSetBits(10, 15) << endl;
}
