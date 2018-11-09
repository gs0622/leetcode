/* https://leetcode.com/problems/counting-bits/description/
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    //vector<int> cnt;
    vector<int> cnt {0};
    int hammingweight(int x) {
        return __builtin_popcount(x);
    }
public:
    vector<int> countBits(int num) {
        if (num > cnt.size()-1) {
            for (int i = cnt.size(); i <= num+1; i++)
                cnt.push_back(hammingweight(i));
        }
        vector<int> r(cnt.begin(), cnt.begin()+num+1);
        return r;
    }
};

int main(void) {
    Solution s;
    vector<int> m = s.countBits(2);
    for (auto x: m) cout << x << " ";
    cout << endl;
    vector<int> n = s.countBits(5);
    for (auto y: n) cout << y << " ";
    cout << endl;
}
