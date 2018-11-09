/* Binary Watch, 12 hrs, 60 mins
 */
#include <bitset>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
	// enumerate 12*60 states
    vector<string> readBinaryWatch(int num) {
        unordered_set<unsigned int> s;
        int h, m;
        for (h = 0; h < 12; h++) {
            for (m = 0; m < 60; m++) {
                int bits = (h << 6) | m;
                s.insert(bits);
            }
        }
        vector<string> r;
        for (auto x: s) {
            bitset<16> b(x);
            if (b.count() == num) {
                h = x >> 6, m = x & 0x3f;
                r.push_back(to_string(h) + ((m < 10)? ":0" : ":") + to_string(m));
            }
        }
        return r;
    }
};
int main(void) {
    int n;
    cin >> n;
    Solution s;
    vector<string> r;
    r = s.readBinaryWatch(n);
    for (auto x: r) cout << x << " ";
    cout << endl;
    return 0;
}
