/* https://leetcode.com/problems/counting-bits/description/
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution2 {
	// Brian Kernighan's algo
	int hammingweight(int x) {
		int res = 0;
		while (x){
			x = x & (x-1), ++res;
		}
		return res;
	}
public:
	int mask(int L, int R) {
		return ((1 << R) - 1) ^ ((1 << (L - 1)) - 1); 
	}
	vector<int> countBits(int num) {
		vector<int> res;
		for (int i=0; i<=num; ++i)
			res.push_back(hammingweight(i));
		return res;
	}
};

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
	Solution2 s;
	vector<int> m = s.countBits(2);
	for (auto x: m) cout << x << " ";
	cout << endl;
	vector<int> n = s.countBits(5);
	for (auto y: n) cout << y << " ";
	cout << endl;

	cout << hex << s.mask(2,5) << endl;
}
