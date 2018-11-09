#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = false;
        auto it = digits.rbegin();
        for (; it != digits.rend(); ++it) {
            if (*it < 9) {
                *it += 1;
                carry = false;
                break;
            } else {
                *it = 0;
                carry = true;
            }
        }
        if (carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main(void) {
    int a[] = {1, 0, 8, 9};
    //vector<int> v(3,9);
    vector<int> v(a, a+4);
    vector<int> r;
    Solution s;
    r = s.plusOne(v);
    for (auto x: r) cout << x;
    cout << endl;
    return 0;
}

