/* Binary Watch, 12 hrs, 60 mins
 */
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
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
            if (__builtin_popcount(x) == num) {
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
