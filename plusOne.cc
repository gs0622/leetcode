/* https://leetcode.com/problems/plus-one/description/
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
You may assume the integer do not contain any leading zero, except the number 0 itself.
The digits are stored such that the most significant digit is at the head of the list.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:								//      0123   0123 
	vector<int> plusOne(vector<int>& digits) {		// e.g, 1199   9999
		for (int i=digits.size()-1; i>=0; --i) {	//      1200  10000
			if (++digits[i] < 10)
				return digits;
			digits[i]=0;
		}
		digits[0]=1, digits.push_back(0);	// tricky: all 9 are carried, change [0] to 1, push_back a '0'
		return digits;
	}

    vector<int> plusOne1(vector<int>& digits) {
        bool carry = false;
        vector<int>::reverse_iterator rit = digits.rbegin();
        *rit += 1;
        if (*rit >= 10) {
            carry = true;
            *rit %= 10;
        }
        for (++rit ;rit != digits.rend(); ++rit) {
            if (carry) {
                *rit += 1, carry = false;
                if (*rit >= 10)
                    carry = true, *rit %= 10;
            }
        }
        if (carry) {
            vector<int>::iterator it = digits.begin();
            digits.insert(it, 1);
        }
        return digits;
    }
};

int main(void) {
	//vector<int> v(3,9);
    vector<int> v{9,9};
    vector<int> r;
    Solution s;
    r = s.plusOne(v);
    for (auto x: r) cout << x;
    cout << endl;
    return 0;
}
