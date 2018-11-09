#include <iostream>
#include <bitset>
using namespace std;
class Solution {
public:
    unsigned int reverseBits(unsigned int n) {
        n = (n & 0xaaaaaaaa) >> 1 | (n & 0x55555555) << 1; // rev 1-bit
        n = (n & 0xcccccccc) >> 2 | (n & 0x33333333) << 2; // rev 2-bit
        n = (n & 0xf0f0f0f0) >> 4 | (n & 0x0f0f0f0f) << 4; // rev 4-bit
        n = (n & 0xff00ff00) >> 8 | (n & 0x00ff00ff) << 8; // rev 8-bit
        n = n >> 16 | n << 16; // rev 16-bit
        return n;
    }
};

int main(void) {
    unsigned int a = 43261596;
    Solution s;
    unsigned int b = s.reverseBits(a);
    std::bitset<32> aa(a);
    std::bitset<32> bb(b);
    cout << aa << ": " << a << endl;
    cout << bb << ": " << b << endl;
    return 0;
}
